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
F_4 ( V_8 , V_2 -> V_17 ) ;
F_5 ( V_8 , V_6 , V_7 ) ;
if ( V_6 != V_18 && V_5 )
* V_5 = ( V_19 * ) V_4 + V_12 ;
while ( V_10 > 0 ) {
unsigned int V_20 = F_6 ( V_4 ) ;
unsigned int V_21 = F_7 (unsigned int, PAGE_SIZE - page_offset,
io_size) ;
V_9 = F_8 ( V_8 , F_9 ( V_4 ) , V_21 , V_20 ) ;
if ( V_9 != V_21 ) {
V_9 = - V_22 ;
goto V_23;
}
V_10 -= V_21 ;
V_4 = ( V_19 * ) V_4 + V_21 ;
}
V_9 = F_10 ( V_8 ) ;
V_23:
F_11 ( V_8 ) ;
return V_9 < 0 ? V_9 : 0 ;
}
static int F_12 ( void * V_24 , struct V_25 * V_26 )
{
T_4 V_27 ;
T_5 V_28 ;
T_6 V_29 ;
V_29 = * ( T_6 * ) ( V_24 + V_30 ) ;
if ( V_29 != F_13 ( V_31 ) &&
V_29 != F_13 ( V_32 ) )
return 0 ;
V_28 = F_14 ( * ( T_6 * ) ( V_24 + V_33 ) ) ;
if ( ! ( V_28 & V_34 ) ||
! ( V_28 & V_35 ) )
return 0 ;
V_26 -> V_36 =
F_15 ( * ( V_37 * ) ( V_24 + V_38 ) ) ;
if ( V_26 -> V_36 < V_39 )
return 0 ;
if ( V_26 -> V_36 % V_39 )
return 0 ;
V_26 -> V_40 =
F_14 ( * ( T_6 * ) ( V_24 + V_41 ) ) ;
V_27 = F_16 ( V_24 + V_42 ) ;
V_26 -> V_43 = ( V_27 >> 16 ) & 0xFFFF ;
V_26 -> V_44 = V_27 & 0xFFFF ;
return 1 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_1 * V_11 , T_1 * V_45 )
{
struct V_46 V_47 ;
struct V_48 V_49 ;
int V_50 ;
* V_11 = 0 ;
* V_45 = F_18 ( V_2 -> V_17 -> V_51 ) >> 9 ;
if ( F_19 ( V_2 ) -> V_52 >= 0 ) {
V_49 . V_53 = F_19 ( V_2 ) -> V_52 ;
V_49 . V_54 = V_55 ;
V_50 = F_20 ( V_2 -> V_17 ,
V_56 , ( unsigned long ) & V_49 ) ;
if ( ! V_50 && ( V_49 . V_57 & V_58 ) == 4 ) {
* V_11 = ( T_1 ) V_49 . V_59 . V_60 << 2 ;
return 0 ;
}
F_21 ( L_1 ) ;
return - V_61 ;
}
V_47 . V_62 = V_55 ;
V_50 = F_20 ( V_2 -> V_17 , V_63 ,
( unsigned long ) & V_47 ) ;
if ( ! V_50 && V_47 . V_64 )
* V_11 = ( T_1 ) V_47 . V_65 . V_60 << 2 ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = F_19 ( V_2 ) ;
struct V_25 V_26 ;
T_1 V_68 , V_69 ;
T_4 V_70 ;
int error = 0 ;
error = - V_61 ;
V_70 = F_23 ( V_2 , V_39 ) ;
if ( ! V_70 )
goto V_23;
if ( F_17 ( V_2 , & V_68 , & V_69 ) )
goto V_23;
error = - V_71 ;
V_67 -> V_72 = F_24 ( F_2 ( V_2 ) , V_73 ) ;
if ( ! V_67 -> V_72 )
goto V_23;
V_67 -> V_74 = F_24 ( F_2 ( V_2 ) , V_73 ) ;
if ( ! V_67 -> V_74 )
goto V_75;
V_76:
error = F_1 ( V_2 , V_68 + V_77 ,
V_67 -> V_72 , ( void * * ) & V_67 -> V_78 ,
V_79 , 0 ) ;
if ( error )
goto V_80;
error = - V_61 ;
switch ( V_67 -> V_78 -> V_81 ) {
case F_13 ( V_32 ) :
F_25 ( V_82 , & V_67 -> V_83 ) ;
case F_13 ( V_31 ) :
break;
case F_13 ( V_84 ) :
if ( ! F_12 ( V_67 -> V_78 , & V_26 ) )
goto V_80;
V_26 . V_36 >>= V_13 ;
V_68 += ( T_1 ) V_26 . V_40 +
( T_1 ) V_26 . V_43 * V_26 . V_36 ;
V_69 = ( T_1 ) V_26 . V_44 * V_26 . V_36 ;
goto V_76;
default:
if ( F_26 ( V_2 , & V_68 , & V_69 ) )
goto V_80;
goto V_76;
}
error = F_1 ( V_2 , V_68 + V_69 - 2 ,
V_67 -> V_74 ,
( void * * ) & V_67 -> V_85 , V_79 ,
0 ) ;
if ( error )
goto V_80;
error = - V_61 ;
if ( V_67 -> V_85 -> V_81 != V_67 -> V_78 -> V_81 ) {
F_27 ( L_2 ) ;
goto V_80;
}
V_70 = F_15 ( V_67 -> V_78 -> V_70 ) ;
if ( V_70 < V_39 || ( ( V_70 - 1 ) & V_70 ) )
goto V_80;
V_67 -> V_86 = V_70 ;
V_67 -> V_87 = F_28 ( V_70 ) ;
V_70 = F_7 ( T_4 , V_67 -> V_86 , V_88 ) ;
while ( V_68 & ( ( V_70 >> V_13 ) - 1 ) )
V_70 >>= 1 ;
if ( F_29 ( V_2 , V_70 ) != V_70 ) {
F_21 ( L_3 , V_70 ) ;
goto V_80;
}
V_67 -> V_89 =
V_68 >> ( V_2 -> V_90 - V_13 ) ;
V_67 -> V_68 = V_68 ;
V_67 -> V_91 = V_69 ;
V_67 -> V_92 = V_67 -> V_87 - V_2 -> V_90 ;
return 0 ;
V_80:
F_30 ( V_67 -> V_74 ) ;
V_75:
F_30 ( V_67 -> V_72 ) ;
V_23:
return error ;
}
