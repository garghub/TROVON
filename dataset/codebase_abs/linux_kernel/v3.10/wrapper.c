static void F_1 ( struct V_1 * V_1 , int V_2 )
{
if ( V_2 )
F_2 ( V_3 , & V_1 -> V_4 ) ;
F_3 ( V_1 -> V_5 ) ;
}
int F_4 ( struct V_6 * V_7 , T_1 V_8 ,
void * V_9 , void * * V_10 , int V_11 )
{
F_5 ( V_12 ) ;
struct V_1 * V_1 ;
int V_13 = 0 ;
T_2 V_14 ;
T_3 V_15 ;
int V_16 ;
V_14 = F_6 ( V_7 ) ;
V_15 = ( T_3 ) V_8 << V_17 ;
V_16 = V_15 & ( V_14 - 1 ) ;
V_8 &= ~ ( ( V_14 >> V_17 ) - 1 ) ;
V_1 = F_7 ( V_18 , 1 ) ;
V_1 -> V_19 = V_8 ;
V_1 -> V_20 = V_7 -> V_21 ;
V_1 -> V_22 = F_1 ;
V_1 -> V_5 = & V_12 ;
if ( ! ( V_11 & V_23 ) && V_10 )
* V_10 = ( V_24 * ) V_9 + V_16 ;
while ( V_14 > 0 ) {
unsigned int V_25 = F_8 ( V_9 ) ;
unsigned int V_26 = F_9 (unsigned int, PAGE_SIZE - page_offset,
io_size) ;
V_13 = F_10 ( V_1 , F_11 ( V_9 ) , V_26 , V_25 ) ;
if ( V_13 != V_26 ) {
V_13 = - V_27 ;
goto V_28;
}
V_14 -= V_26 ;
V_9 = ( V_24 * ) V_9 + V_26 ;
}
F_12 ( V_11 , V_1 ) ;
F_13 ( & V_12 ) ;
if ( ! F_14 ( V_1 , V_3 ) )
V_13 = - V_27 ;
V_28:
F_15 ( V_1 ) ;
return V_13 < 0 ? V_13 : 0 ;
}
static int F_16 ( void * V_29 , struct V_30 * V_31 )
{
T_4 V_32 ;
T_5 V_33 ;
T_6 V_34 ;
V_34 = * ( T_6 * ) ( V_29 + V_35 ) ;
if ( V_34 != F_17 ( V_36 ) &&
V_34 != F_17 ( V_37 ) )
return 0 ;
V_33 = F_18 ( * ( T_6 * ) ( V_29 + V_38 ) ) ;
if ( ! ( V_33 & V_39 ) ||
! ( V_33 & V_40 ) )
return 0 ;
V_31 -> V_41 =
F_19 ( * ( V_42 * ) ( V_29 + V_43 ) ) ;
if ( V_31 -> V_41 < V_44 )
return 0 ;
if ( V_31 -> V_41 % V_44 )
return 0 ;
V_31 -> V_45 =
F_18 ( * ( T_6 * ) ( V_29 + V_46 ) ) ;
V_32 = F_20 ( V_29 + V_47 ) ;
V_31 -> V_48 = ( V_32 >> 16 ) & 0xFFFF ;
V_31 -> V_49 = V_32 & 0xFFFF ;
return 1 ;
}
static int F_21 ( struct V_6 * V_7 ,
T_1 * V_15 , T_1 * V_50 )
{
struct V_51 V_52 ;
struct V_53 V_54 ;
int V_55 ;
* V_15 = 0 ;
* V_50 = V_7 -> V_21 -> V_56 -> V_57 >> 9 ;
if ( F_22 ( V_7 ) -> V_58 >= 0 ) {
V_54 . V_59 = F_22 ( V_7 ) -> V_58 ;
V_54 . V_60 = V_61 ;
V_55 = F_23 ( V_7 -> V_21 ,
V_62 , ( unsigned long ) & V_54 ) ;
if ( ! V_55 && ( V_54 . V_63 & V_64 ) == 4 ) {
* V_15 = ( T_1 ) V_54 . V_65 . V_66 << 2 ;
return 0 ;
}
F_24 ( L_1 ) ;
return - V_67 ;
}
V_52 . V_68 = V_61 ;
V_55 = F_23 ( V_7 -> V_21 , V_69 ,
( unsigned long ) & V_52 ) ;
if ( ! V_55 && V_52 . V_70 )
* V_15 = ( T_1 ) V_52 . V_71 . V_66 << 2 ;
return 0 ;
}
int F_25 ( struct V_6 * V_7 )
{
struct V_72 * V_73 = F_22 ( V_7 ) ;
struct V_30 V_31 ;
T_1 V_74 , V_75 ;
T_4 V_76 ;
int error = 0 ;
error = - V_67 ;
V_76 = F_26 ( V_7 , V_44 ) ;
if ( ! V_76 )
goto V_28;
if ( F_21 ( V_7 , & V_74 , & V_75 ) )
goto V_28;
error = - V_77 ;
V_73 -> V_78 = F_27 ( F_6 ( V_7 ) , V_79 ) ;
if ( ! V_73 -> V_78 )
goto V_28;
V_73 -> V_80 = F_27 ( F_6 ( V_7 ) , V_79 ) ;
if ( ! V_73 -> V_80 )
goto V_81;
V_82:
error = F_4 ( V_7 , V_74 + V_83 ,
V_73 -> V_78 , ( void * * ) & V_73 -> V_84 ,
V_85 ) ;
if ( error )
goto V_86;
error = - V_67 ;
switch ( V_73 -> V_84 -> V_87 ) {
case F_17 ( V_37 ) :
F_28 ( V_88 , & V_73 -> V_89 ) ;
case F_17 ( V_36 ) :
break;
case F_17 ( V_90 ) :
if ( ! F_16 ( V_73 -> V_84 , & V_31 ) )
goto V_86;
V_31 . V_41 >>= V_17 ;
V_74 += ( T_1 ) V_31 . V_45 +
( T_1 ) V_31 . V_48 * V_31 . V_41 ;
V_75 = ( T_1 ) V_31 . V_49 * V_31 . V_41 ;
goto V_82;
default:
if ( F_29 ( V_7 , & V_74 , & V_75 ) )
goto V_86;
goto V_82;
}
error = F_4 ( V_7 , V_74 + V_75 - 2 ,
V_73 -> V_80 ,
( void * * ) & V_73 -> V_91 , V_85 ) ;
if ( error )
goto V_86;
error = - V_67 ;
if ( V_73 -> V_91 -> V_87 != V_73 -> V_84 -> V_87 ) {
F_30 ( L_2 ) ;
goto V_86;
}
V_76 = F_19 ( V_73 -> V_84 -> V_76 ) ;
if ( V_76 < V_44 || ( ( V_76 - 1 ) & V_76 ) )
goto V_86;
V_73 -> V_92 = V_76 ;
V_73 -> V_93 = 0 ;
while ( ( V_76 >>= 1 ) != 0 )
V_73 -> V_93 ++ ;
V_76 = F_31 ( V_73 -> V_92 , ( T_4 ) V_94 ) ;
while ( V_74 & ( ( V_76 >> V_17 ) - 1 ) )
V_76 >>= 1 ;
if ( F_32 ( V_7 , V_76 ) != V_76 ) {
F_24 ( L_3 , V_76 ) ;
goto V_86;
}
V_73 -> V_95 =
V_74 >> ( V_7 -> V_96 - V_17 ) ;
V_73 -> V_74 = V_74 ;
V_73 -> V_97 = V_75 ;
V_73 -> V_98 = V_73 -> V_93 - V_7 -> V_96 ;
return 0 ;
V_86:
F_33 ( V_73 -> V_80 ) ;
V_81:
F_33 ( V_73 -> V_78 ) ;
V_28:
return error ;
}
