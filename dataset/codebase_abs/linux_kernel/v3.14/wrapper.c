int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , void * * V_5 , int V_6 )
{
struct V_7 * V_7 ;
int V_8 = 0 ;
T_2 V_9 ;
T_3 V_10 ;
int V_11 ;
V_9 = F_2 ( V_2 ) ;
V_10 = ( T_3 ) V_3 << V_12 ;
V_11 = V_10 & ( V_9 - 1 ) ;
V_3 &= ~ ( ( V_9 >> V_12 ) - 1 ) ;
V_7 = F_3 ( V_13 , 1 ) ;
V_7 -> V_14 . V_15 = V_3 ;
V_7 -> V_16 = V_2 -> V_17 ;
if ( ! ( V_6 & V_18 ) && V_5 )
* V_5 = ( V_19 * ) V_4 + V_11 ;
while ( V_9 > 0 ) {
unsigned int V_20 = F_4 ( V_4 ) ;
unsigned int V_21 = F_5 (unsigned int, PAGE_SIZE - page_offset,
io_size) ;
V_8 = F_6 ( V_7 , F_7 ( V_4 ) , V_21 , V_20 ) ;
if ( V_8 != V_21 ) {
V_8 = - V_22 ;
goto V_23;
}
V_9 -= V_21 ;
V_4 = ( V_19 * ) V_4 + V_21 ;
}
V_8 = F_8 ( V_6 , V_7 ) ;
V_23:
F_9 ( V_7 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
static int F_10 ( void * V_24 , struct V_25 * V_26 )
{
T_4 V_27 ;
T_5 V_28 ;
T_6 V_29 ;
V_29 = * ( T_6 * ) ( V_24 + V_30 ) ;
if ( V_29 != F_11 ( V_31 ) &&
V_29 != F_11 ( V_32 ) )
return 0 ;
V_28 = F_12 ( * ( T_6 * ) ( V_24 + V_33 ) ) ;
if ( ! ( V_28 & V_34 ) ||
! ( V_28 & V_35 ) )
return 0 ;
V_26 -> V_36 =
F_13 ( * ( V_37 * ) ( V_24 + V_38 ) ) ;
if ( V_26 -> V_36 < V_39 )
return 0 ;
if ( V_26 -> V_36 % V_39 )
return 0 ;
V_26 -> V_40 =
F_12 ( * ( T_6 * ) ( V_24 + V_41 ) ) ;
V_27 = F_14 ( V_24 + V_42 ) ;
V_26 -> V_43 = ( V_27 >> 16 ) & 0xFFFF ;
V_26 -> V_44 = V_27 & 0xFFFF ;
return 1 ;
}
static int F_15 ( struct V_1 * V_2 ,
T_1 * V_10 , T_1 * V_45 )
{
struct V_46 V_47 ;
struct V_48 V_49 ;
int V_50 ;
* V_10 = 0 ;
* V_45 = V_2 -> V_17 -> V_51 -> V_52 >> 9 ;
if ( F_16 ( V_2 ) -> V_53 >= 0 ) {
V_49 . V_54 = F_16 ( V_2 ) -> V_53 ;
V_49 . V_55 = V_56 ;
V_50 = F_17 ( V_2 -> V_17 ,
V_57 , ( unsigned long ) & V_49 ) ;
if ( ! V_50 && ( V_49 . V_58 & V_59 ) == 4 ) {
* V_10 = ( T_1 ) V_49 . V_60 . V_61 << 2 ;
return 0 ;
}
F_18 ( L_1 ) ;
return - V_62 ;
}
V_47 . V_63 = V_56 ;
V_50 = F_17 ( V_2 -> V_17 , V_64 ,
( unsigned long ) & V_47 ) ;
if ( ! V_50 && V_47 . V_65 )
* V_10 = ( T_1 ) V_47 . V_66 . V_61 << 2 ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = F_16 ( V_2 ) ;
struct V_25 V_26 ;
T_1 V_69 , V_70 ;
T_4 V_71 ;
int error = 0 ;
error = - V_62 ;
V_71 = F_20 ( V_2 , V_39 ) ;
if ( ! V_71 )
goto V_23;
if ( F_15 ( V_2 , & V_69 , & V_70 ) )
goto V_23;
error = - V_72 ;
V_68 -> V_73 = F_21 ( F_2 ( V_2 ) , V_74 ) ;
if ( ! V_68 -> V_73 )
goto V_23;
V_68 -> V_75 = F_21 ( F_2 ( V_2 ) , V_74 ) ;
if ( ! V_68 -> V_75 )
goto V_76;
V_77:
error = F_1 ( V_2 , V_69 + V_78 ,
V_68 -> V_73 , ( void * * ) & V_68 -> V_79 ,
V_80 ) ;
if ( error )
goto V_81;
error = - V_62 ;
switch ( V_68 -> V_79 -> V_82 ) {
case F_11 ( V_32 ) :
F_22 ( V_83 , & V_68 -> V_84 ) ;
case F_11 ( V_31 ) :
break;
case F_11 ( V_85 ) :
if ( ! F_10 ( V_68 -> V_79 , & V_26 ) )
goto V_81;
V_26 . V_36 >>= V_12 ;
V_69 += ( T_1 ) V_26 . V_40 +
( T_1 ) V_26 . V_43 * V_26 . V_36 ;
V_70 = ( T_1 ) V_26 . V_44 * V_26 . V_36 ;
goto V_77;
default:
if ( F_23 ( V_2 , & V_69 , & V_70 ) )
goto V_81;
goto V_77;
}
error = F_1 ( V_2 , V_69 + V_70 - 2 ,
V_68 -> V_75 ,
( void * * ) & V_68 -> V_86 , V_80 ) ;
if ( error )
goto V_81;
error = - V_62 ;
if ( V_68 -> V_86 -> V_82 != V_68 -> V_79 -> V_82 ) {
F_24 ( L_2 ) ;
goto V_81;
}
V_71 = F_13 ( V_68 -> V_79 -> V_71 ) ;
if ( V_71 < V_39 || ( ( V_71 - 1 ) & V_71 ) )
goto V_81;
V_68 -> V_87 = V_71 ;
V_68 -> V_88 = 0 ;
while ( ( V_71 >>= 1 ) != 0 )
V_68 -> V_88 ++ ;
V_71 = F_25 ( V_68 -> V_87 , ( T_4 ) V_89 ) ;
while ( V_69 & ( ( V_71 >> V_12 ) - 1 ) )
V_71 >>= 1 ;
if ( F_26 ( V_2 , V_71 ) != V_71 ) {
F_18 ( L_3 , V_71 ) ;
goto V_81;
}
V_68 -> V_90 =
V_69 >> ( V_2 -> V_91 - V_12 ) ;
V_68 -> V_69 = V_69 ;
V_68 -> V_92 = V_70 ;
V_68 -> V_93 = V_68 -> V_88 - V_2 -> V_91 ;
return 0 ;
V_81:
F_27 ( V_68 -> V_75 ) ;
V_76:
F_27 ( V_68 -> V_73 ) ;
V_23:
return error ;
}
