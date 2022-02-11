static void F_1 ( struct V_1 * V_1 , int V_2 )
{
if ( V_2 )
F_2 ( V_3 , & V_1 -> V_4 ) ;
F_3 ( V_1 -> V_5 ) ;
}
int F_4 ( struct V_6 * V_7 , T_1 V_8 ,
void * V_9 , int V_10 )
{
F_5 ( V_11 ) ;
struct V_1 * V_1 ;
int V_12 = 0 ;
V_1 = F_6 ( V_13 , 1 ) ;
V_1 -> V_14 = V_8 ;
V_1 -> V_15 = V_7 ;
V_1 -> V_16 = F_1 ;
V_1 -> V_5 = & V_11 ;
if ( F_7 ( V_1 , F_8 ( V_9 ) , V_17 ,
F_9 ( V_9 ) ) != V_17 )
F_10 () ;
F_11 ( V_10 , V_1 ) ;
F_12 ( & V_11 ) ;
if ( ! F_13 ( V_1 , V_3 ) )
V_12 = - V_18 ;
F_14 ( V_1 ) ;
return V_12 ;
}
static int F_15 ( void * V_19 , struct V_20 * V_21 )
{
T_2 V_22 ;
T_3 V_23 ;
T_4 V_24 ;
V_24 = * ( T_4 * ) ( V_19 + V_25 ) ;
if ( V_24 != F_16 ( V_26 ) &&
V_24 != F_16 ( V_27 ) )
return 0 ;
V_23 = F_17 ( * ( T_4 * ) ( V_19 + V_28 ) ) ;
if ( ! ( V_23 & V_29 ) ||
! ( V_23 & V_30 ) )
return 0 ;
V_21 -> V_31 =
F_18 ( * ( V_32 * ) ( V_19 + V_33 ) ) ;
if ( V_21 -> V_31 < V_17 )
return 0 ;
if ( V_21 -> V_31 % V_17 )
return 0 ;
V_21 -> V_34 =
F_17 ( * ( T_4 * ) ( V_19 + V_35 ) ) ;
V_22 = F_19 ( V_19 + V_36 ) ;
V_21 -> V_37 = ( V_22 >> 16 ) & 0xFFFF ;
V_21 -> V_38 = V_22 & 0xFFFF ;
return 1 ;
}
static int F_20 ( struct V_39 * V_40 ,
T_1 * V_41 , T_1 * V_42 )
{
struct V_43 V_44 ;
struct V_45 V_46 ;
int V_47 ;
* V_41 = 0 ;
* V_42 = V_40 -> V_48 -> V_49 -> V_50 >> 9 ;
if ( F_21 ( V_40 ) -> V_51 >= 0 ) {
V_46 . V_52 = F_21 ( V_40 ) -> V_51 ;
V_46 . V_53 = V_54 ;
V_47 = F_22 ( V_40 -> V_48 ,
V_55 , ( unsigned long ) & V_46 ) ;
if ( ! V_47 && ( V_46 . V_56 & V_57 ) == 4 ) {
* V_41 = ( T_1 ) V_46 . V_58 . V_59 << 2 ;
return 0 ;
}
F_23 ( V_60 L_1 ) ;
return - V_61 ;
}
V_44 . V_62 = V_54 ;
V_47 = F_22 ( V_40 -> V_48 , V_63 ,
( unsigned long ) & V_44 ) ;
if ( ! V_47 && V_44 . V_64 )
* V_41 = ( T_1 ) V_44 . V_65 . V_59 << 2 ;
return 0 ;
}
int F_24 ( struct V_39 * V_40 )
{
struct V_66 * V_67 = F_21 ( V_40 ) ;
struct V_20 V_21 ;
T_1 V_68 , V_69 ;
T_2 V_70 ;
int error = 0 ;
error = - V_61 ;
V_70 = F_25 ( V_40 , V_17 ) ;
if ( ! V_70 )
goto V_71;
if ( F_20 ( V_40 , & V_68 , & V_69 ) )
goto V_71;
if ( ( V_72 ) V_68 + V_69 > 0x100000000ULL ) {
F_26 ( L_2 ) ;
goto V_71;
}
error = - V_73 ;
V_67 -> V_74 = F_27 ( V_17 , V_75 ) ;
if ( ! V_67 -> V_74 )
goto V_71;
V_67 -> V_76 = F_27 ( V_17 , V_75 ) ;
if ( ! V_67 -> V_76 )
goto V_77;
V_78:
error = F_4 ( V_40 -> V_48 ,
V_68 + V_79 ,
V_67 -> V_74 , V_80 ) ;
if ( error )
goto V_81;
error = - V_61 ;
switch ( V_67 -> V_74 -> V_82 ) {
case F_16 ( V_27 ) :
F_28 ( V_83 , & V_67 -> V_84 ) ;
case F_16 ( V_26 ) :
break;
case F_16 ( V_85 ) :
if ( ! F_15 ( V_67 -> V_74 , & V_21 ) )
goto V_81;
V_21 . V_31 >>= V_86 ;
V_68 += V_21 . V_34 + V_21 . V_37 * V_21 . V_31 ;
V_69 = V_21 . V_38 * V_21 . V_31 ;
goto V_78;
default:
if ( F_29 ( V_40 , & V_68 , & V_69 ) )
goto V_81;
goto V_78;
}
error = F_4 ( V_40 -> V_48 ,
V_68 + V_69 - 2 ,
V_67 -> V_76 , V_80 ) ;
if ( error )
goto V_81;
error = - V_61 ;
if ( V_67 -> V_76 -> V_82 != V_67 -> V_74 -> V_82 ) {
F_23 ( V_87
L_3 ) ;
goto V_81;
}
V_70 = F_18 ( V_67 -> V_74 -> V_70 ) ;
if ( V_70 < V_17 || ( ( V_70 - 1 ) & V_70 ) )
goto V_81;
V_67 -> V_88 = V_70 ;
V_67 -> V_89 = 0 ;
while ( ( V_70 >>= 1 ) != 0 )
V_67 -> V_89 ++ ;
V_70 = F_30 ( V_67 -> V_88 , ( T_2 ) V_90 ) ;
while ( V_68 & ( ( V_70 >> V_86 ) - 1 ) )
V_70 >>= 1 ;
if ( F_31 ( V_40 , V_70 ) != V_70 ) {
F_23 ( V_60 L_4 ,
V_70 ) ;
goto V_81;
}
V_67 -> V_91 =
V_68 >> ( V_40 -> V_92 - V_86 ) ;
V_67 -> V_68 = V_68 ;
V_67 -> V_93 = V_69 ;
V_67 -> V_94 = V_67 -> V_89 - V_40 -> V_92 ;
return 0 ;
V_81:
F_32 ( V_67 -> V_76 ) ;
V_77:
F_32 ( V_67 -> V_74 ) ;
V_71:
return error ;
}
