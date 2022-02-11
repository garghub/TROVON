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
V_7 -> V_14 = V_3 ;
V_7 -> V_15 = V_2 -> V_16 ;
if ( ! ( V_6 & V_17 ) && V_5 )
* V_5 = ( V_18 * ) V_4 + V_11 ;
while ( V_9 > 0 ) {
unsigned int V_19 = F_4 ( V_4 ) ;
unsigned int V_20 = F_5 (unsigned int, PAGE_SIZE - page_offset,
io_size) ;
V_8 = F_6 ( V_7 , F_7 ( V_4 ) , V_20 , V_19 ) ;
if ( V_8 != V_20 ) {
V_8 = - V_21 ;
goto V_22;
}
V_9 -= V_20 ;
V_4 = ( V_18 * ) V_4 + V_20 ;
}
V_8 = F_8 ( V_6 , V_7 ) ;
V_22:
F_9 ( V_7 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
static int F_10 ( void * V_23 , struct V_24 * V_25 )
{
T_4 V_26 ;
T_5 V_27 ;
T_6 V_28 ;
V_28 = * ( T_6 * ) ( V_23 + V_29 ) ;
if ( V_28 != F_11 ( V_30 ) &&
V_28 != F_11 ( V_31 ) )
return 0 ;
V_27 = F_12 ( * ( T_6 * ) ( V_23 + V_32 ) ) ;
if ( ! ( V_27 & V_33 ) ||
! ( V_27 & V_34 ) )
return 0 ;
V_25 -> V_35 =
F_13 ( * ( V_36 * ) ( V_23 + V_37 ) ) ;
if ( V_25 -> V_35 < V_38 )
return 0 ;
if ( V_25 -> V_35 % V_38 )
return 0 ;
V_25 -> V_39 =
F_12 ( * ( T_6 * ) ( V_23 + V_40 ) ) ;
V_26 = F_14 ( V_23 + V_41 ) ;
V_25 -> V_42 = ( V_26 >> 16 ) & 0xFFFF ;
V_25 -> V_43 = V_26 & 0xFFFF ;
return 1 ;
}
static int F_15 ( struct V_1 * V_2 ,
T_1 * V_10 , T_1 * V_44 )
{
struct V_45 V_46 ;
struct V_47 V_48 ;
int V_49 ;
* V_10 = 0 ;
* V_44 = V_2 -> V_16 -> V_50 -> V_51 >> 9 ;
if ( F_16 ( V_2 ) -> V_52 >= 0 ) {
V_48 . V_53 = F_16 ( V_2 ) -> V_52 ;
V_48 . V_54 = V_55 ;
V_49 = F_17 ( V_2 -> V_16 ,
V_56 , ( unsigned long ) & V_48 ) ;
if ( ! V_49 && ( V_48 . V_57 & V_58 ) == 4 ) {
* V_10 = ( T_1 ) V_48 . V_59 . V_60 << 2 ;
return 0 ;
}
F_18 ( L_1 ) ;
return - V_61 ;
}
V_46 . V_62 = V_55 ;
V_49 = F_17 ( V_2 -> V_16 , V_63 ,
( unsigned long ) & V_46 ) ;
if ( ! V_49 && V_46 . V_64 )
* V_10 = ( T_1 ) V_46 . V_65 . V_60 << 2 ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = F_16 ( V_2 ) ;
struct V_24 V_25 ;
T_1 V_68 , V_69 ;
T_4 V_70 ;
int error = 0 ;
error = - V_61 ;
V_70 = F_20 ( V_2 , V_38 ) ;
if ( ! V_70 )
goto V_22;
if ( F_15 ( V_2 , & V_68 , & V_69 ) )
goto V_22;
error = - V_71 ;
V_67 -> V_72 = F_21 ( F_2 ( V_2 ) , V_73 ) ;
if ( ! V_67 -> V_72 )
goto V_22;
V_67 -> V_74 = F_21 ( F_2 ( V_2 ) , V_73 ) ;
if ( ! V_67 -> V_74 )
goto V_75;
V_76:
error = F_1 ( V_2 , V_68 + V_77 ,
V_67 -> V_72 , ( void * * ) & V_67 -> V_78 ,
V_79 ) ;
if ( error )
goto V_80;
error = - V_61 ;
switch ( V_67 -> V_78 -> V_81 ) {
case F_11 ( V_31 ) :
F_22 ( V_82 , & V_67 -> V_83 ) ;
case F_11 ( V_30 ) :
break;
case F_11 ( V_84 ) :
if ( ! F_10 ( V_67 -> V_78 , & V_25 ) )
goto V_80;
V_25 . V_35 >>= V_12 ;
V_68 += ( T_1 ) V_25 . V_39 +
( T_1 ) V_25 . V_42 * V_25 . V_35 ;
V_69 = ( T_1 ) V_25 . V_43 * V_25 . V_35 ;
goto V_76;
default:
if ( F_23 ( V_2 , & V_68 , & V_69 ) )
goto V_80;
goto V_76;
}
error = F_1 ( V_2 , V_68 + V_69 - 2 ,
V_67 -> V_74 ,
( void * * ) & V_67 -> V_85 , V_79 ) ;
if ( error )
goto V_80;
error = - V_61 ;
if ( V_67 -> V_85 -> V_81 != V_67 -> V_78 -> V_81 ) {
F_24 ( L_2 ) ;
goto V_80;
}
V_70 = F_13 ( V_67 -> V_78 -> V_70 ) ;
if ( V_70 < V_38 || ( ( V_70 - 1 ) & V_70 ) )
goto V_80;
V_67 -> V_86 = V_70 ;
V_67 -> V_87 = 0 ;
while ( ( V_70 >>= 1 ) != 0 )
V_67 -> V_87 ++ ;
V_70 = F_25 ( V_67 -> V_86 , ( T_4 ) V_88 ) ;
while ( V_68 & ( ( V_70 >> V_12 ) - 1 ) )
V_70 >>= 1 ;
if ( F_26 ( V_2 , V_70 ) != V_70 ) {
F_18 ( L_3 , V_70 ) ;
goto V_80;
}
V_67 -> V_89 =
V_68 >> ( V_2 -> V_90 - V_12 ) ;
V_67 -> V_68 = V_68 ;
V_67 -> V_91 = V_69 ;
V_67 -> V_92 = V_67 -> V_87 - V_2 -> V_90 ;
return 0 ;
V_80:
F_27 ( V_67 -> V_74 ) ;
V_75:
F_27 ( V_67 -> V_72 ) ;
V_22:
return error ;
}
