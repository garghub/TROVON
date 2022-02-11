int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , void * * V_5 , int V_6 , int V_7 )
{
struct V_8 * V_8 ;
int V_9 = 0 ;
T_2 V_10 ;
T_3 V_11 ;
int V_12 ;
V_10 = F_2 ( V_2 ) ;
V_11 = ( T_3 ) V_3 << V_13 ;
V_12 = V_11 & ( V_10 - 1 ) ;
V_3 &= ~ ( ( V_10 >> V_13 ) - 1 ) ;
V_8 = F_3 ( V_14 , 1 ) ;
V_8 -> V_15 . V_16 = V_3 ;
V_8 -> V_17 = V_2 -> V_18 ;
F_4 ( V_8 , V_6 , V_7 ) ;
if ( V_6 != V_19 && V_5 )
* V_5 = ( V_20 * ) V_4 + V_12 ;
while ( V_10 > 0 ) {
unsigned int V_21 = F_5 ( V_4 ) ;
unsigned int V_22 = F_6 (unsigned int, PAGE_SIZE - page_offset,
io_size) ;
V_9 = F_7 ( V_8 , F_8 ( V_4 ) , V_22 , V_21 ) ;
if ( V_9 != V_22 ) {
V_9 = - V_23 ;
goto V_24;
}
V_10 -= V_22 ;
V_4 = ( V_20 * ) V_4 + V_22 ;
}
V_9 = F_9 ( V_8 ) ;
V_24:
F_10 ( V_8 ) ;
return V_9 < 0 ? V_9 : 0 ;
}
static int F_11 ( void * V_25 , struct V_26 * V_27 )
{
T_4 V_28 ;
T_5 V_29 ;
T_6 V_30 ;
V_30 = * ( T_6 * ) ( V_25 + V_31 ) ;
if ( V_30 != F_12 ( V_32 ) &&
V_30 != F_12 ( V_33 ) )
return 0 ;
V_29 = F_13 ( * ( T_6 * ) ( V_25 + V_34 ) ) ;
if ( ! ( V_29 & V_35 ) ||
! ( V_29 & V_36 ) )
return 0 ;
V_27 -> V_37 =
F_14 ( * ( V_38 * ) ( V_25 + V_39 ) ) ;
if ( V_27 -> V_37 < V_40 )
return 0 ;
if ( V_27 -> V_37 % V_40 )
return 0 ;
V_27 -> V_41 =
F_13 ( * ( T_6 * ) ( V_25 + V_42 ) ) ;
V_28 = F_15 ( V_25 + V_43 ) ;
V_27 -> V_44 = ( V_28 >> 16 ) & 0xFFFF ;
V_27 -> V_45 = V_28 & 0xFFFF ;
return 1 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_1 * V_11 , T_1 * V_46 )
{
struct V_47 V_48 ;
struct V_49 V_50 ;
int V_51 ;
* V_11 = 0 ;
* V_46 = F_17 ( V_2 -> V_18 -> V_52 ) >> 9 ;
if ( F_18 ( V_2 ) -> V_53 >= 0 ) {
V_50 . V_54 = F_18 ( V_2 ) -> V_53 ;
V_50 . V_55 = V_56 ;
V_51 = F_19 ( V_2 -> V_18 ,
V_57 , ( unsigned long ) & V_50 ) ;
if ( ! V_51 && ( V_50 . V_58 & V_59 ) == 4 ) {
* V_11 = ( T_1 ) V_50 . V_60 . V_61 << 2 ;
return 0 ;
}
F_20 ( L_1 ) ;
return - V_62 ;
}
V_48 . V_63 = V_56 ;
V_51 = F_19 ( V_2 -> V_18 , V_64 ,
( unsigned long ) & V_48 ) ;
if ( ! V_51 && V_48 . V_65 )
* V_11 = ( T_1 ) V_48 . V_66 . V_61 << 2 ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = F_18 ( V_2 ) ;
struct V_26 V_27 ;
T_1 V_69 , V_70 ;
T_4 V_71 ;
int error = 0 ;
error = - V_62 ;
V_71 = F_22 ( V_2 , V_40 ) ;
if ( ! V_71 )
goto V_24;
if ( F_16 ( V_2 , & V_69 , & V_70 ) )
goto V_24;
error = - V_72 ;
V_68 -> V_73 = F_23 ( F_2 ( V_2 ) , V_74 ) ;
if ( ! V_68 -> V_73 )
goto V_24;
V_68 -> V_75 = F_23 ( F_2 ( V_2 ) , V_74 ) ;
if ( ! V_68 -> V_75 )
goto V_76;
V_77:
error = F_1 ( V_2 , V_69 + V_78 ,
V_68 -> V_73 , ( void * * ) & V_68 -> V_79 ,
V_80 , 0 ) ;
if ( error )
goto V_81;
error = - V_62 ;
switch ( V_68 -> V_79 -> V_82 ) {
case F_12 ( V_33 ) :
F_24 ( V_83 , & V_68 -> V_84 ) ;
case F_12 ( V_32 ) :
break;
case F_12 ( V_85 ) :
if ( ! F_11 ( V_68 -> V_79 , & V_27 ) )
goto V_81;
V_27 . V_37 >>= V_13 ;
V_69 += ( T_1 ) V_27 . V_41 +
( T_1 ) V_27 . V_44 * V_27 . V_37 ;
V_70 = ( T_1 ) V_27 . V_45 * V_27 . V_37 ;
goto V_77;
default:
if ( F_25 ( V_2 , & V_69 , & V_70 ) )
goto V_81;
goto V_77;
}
error = F_1 ( V_2 , V_69 + V_70 - 2 ,
V_68 -> V_75 ,
( void * * ) & V_68 -> V_86 , V_80 ,
0 ) ;
if ( error )
goto V_81;
error = - V_62 ;
if ( V_68 -> V_86 -> V_82 != V_68 -> V_79 -> V_82 ) {
F_26 ( L_2 ) ;
goto V_81;
}
V_71 = F_14 ( V_68 -> V_79 -> V_71 ) ;
if ( V_71 < V_40 || ( ( V_71 - 1 ) & V_71 ) )
goto V_81;
V_68 -> V_87 = V_71 ;
V_68 -> V_88 = F_27 ( V_71 ) ;
V_71 = F_6 ( T_4 , V_68 -> V_87 , V_89 ) ;
while ( V_69 & ( ( V_71 >> V_13 ) - 1 ) )
V_71 >>= 1 ;
if ( F_28 ( V_2 , V_71 ) != V_71 ) {
F_20 ( L_3 , V_71 ) ;
goto V_81;
}
V_68 -> V_90 =
V_69 >> ( V_2 -> V_91 - V_13 ) ;
V_68 -> V_69 = V_69 ;
V_68 -> V_92 = V_70 ;
V_68 -> V_93 = V_68 -> V_88 - V_2 -> V_91 ;
return 0 ;
V_81:
F_29 ( V_68 -> V_75 ) ;
V_76:
F_29 ( V_68 -> V_73 ) ;
V_24:
return error ;
}
