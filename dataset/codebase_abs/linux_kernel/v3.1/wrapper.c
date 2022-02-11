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
unsigned int V_14 ;
T_2 V_15 ;
int V_16 ;
V_14 = F_6 ( V_7 ) ;
V_15 = ( T_2 ) V_8 << V_17 ;
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
T_3 V_32 ;
T_4 V_33 ;
T_5 V_34 ;
V_34 = * ( T_5 * ) ( V_29 + V_35 ) ;
if ( V_34 != F_17 ( V_36 ) &&
V_34 != F_17 ( V_37 ) )
return 0 ;
V_33 = F_18 ( * ( T_5 * ) ( V_29 + V_38 ) ) ;
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
F_18 ( * ( T_5 * ) ( V_29 + V_46 ) ) ;
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
F_24 ( V_67 L_1 ) ;
return - V_68 ;
}
V_52 . V_69 = V_61 ;
V_55 = F_23 ( V_7 -> V_21 , V_70 ,
( unsigned long ) & V_52 ) ;
if ( ! V_55 && V_52 . V_71 )
* V_15 = ( T_1 ) V_52 . V_72 . V_66 << 2 ;
return 0 ;
}
int F_25 ( struct V_6 * V_7 )
{
struct V_73 * V_74 = F_22 ( V_7 ) ;
struct V_30 V_31 ;
T_1 V_75 , V_76 ;
T_3 V_77 ;
int error = 0 ;
error = - V_68 ;
V_77 = F_26 ( V_7 , V_44 ) ;
if ( ! V_77 )
goto V_28;
if ( F_21 ( V_7 , & V_75 , & V_76 ) )
goto V_28;
error = - V_78 ;
V_74 -> V_79 = F_27 ( F_6 ( V_7 ) , V_80 ) ;
if ( ! V_74 -> V_79 )
goto V_28;
V_74 -> V_81 = F_27 ( F_6 ( V_7 ) , V_80 ) ;
if ( ! V_74 -> V_81 )
goto V_82;
V_83:
error = F_4 ( V_7 , V_75 + V_84 ,
V_74 -> V_79 , ( void * * ) & V_74 -> V_85 ,
V_86 ) ;
if ( error )
goto V_87;
error = - V_68 ;
switch ( V_74 -> V_85 -> V_88 ) {
case F_17 ( V_37 ) :
F_28 ( V_89 , & V_74 -> V_90 ) ;
case F_17 ( V_36 ) :
break;
case F_17 ( V_91 ) :
if ( ! F_16 ( V_74 -> V_85 , & V_31 ) )
goto V_87;
V_31 . V_41 >>= V_17 ;
V_75 += ( T_1 ) V_31 . V_45 +
( T_1 ) V_31 . V_48 * V_31 . V_41 ;
V_76 = ( T_1 ) V_31 . V_49 * V_31 . V_41 ;
goto V_83;
default:
if ( F_29 ( V_7 , & V_75 , & V_76 ) )
goto V_87;
goto V_83;
}
error = F_4 ( V_7 , V_75 + V_76 - 2 ,
V_74 -> V_81 ,
( void * * ) & V_74 -> V_92 , V_86 ) ;
if ( error )
goto V_87;
error = - V_68 ;
if ( V_74 -> V_92 -> V_88 != V_74 -> V_85 -> V_88 ) {
F_24 ( V_93
L_2 ) ;
goto V_87;
}
V_77 = F_19 ( V_74 -> V_85 -> V_77 ) ;
if ( V_77 < V_44 || ( ( V_77 - 1 ) & V_77 ) )
goto V_87;
V_74 -> V_94 = V_77 ;
V_74 -> V_95 = 0 ;
while ( ( V_77 >>= 1 ) != 0 )
V_74 -> V_95 ++ ;
V_77 = F_30 ( V_74 -> V_94 , ( T_3 ) V_96 ) ;
while ( V_75 & ( ( V_77 >> V_17 ) - 1 ) )
V_77 >>= 1 ;
if ( F_31 ( V_7 , V_77 ) != V_77 ) {
F_24 ( V_67 L_3 ,
V_77 ) ;
goto V_87;
}
V_74 -> V_97 =
V_75 >> ( V_7 -> V_98 - V_17 ) ;
V_74 -> V_75 = V_75 ;
V_74 -> V_99 = V_76 ;
V_74 -> V_100 = V_74 -> V_95 - V_7 -> V_98 ;
return 0 ;
V_87:
F_32 ( V_74 -> V_81 ) ;
V_82:
F_32 ( V_74 -> V_79 ) ;
V_28:
return error ;
}
