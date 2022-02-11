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
* V_46 = V_2 -> V_18 -> V_52 -> V_53 >> 9 ;
if ( F_17 ( V_2 ) -> V_54 >= 0 ) {
V_50 . V_55 = F_17 ( V_2 ) -> V_54 ;
V_50 . V_56 = V_57 ;
V_51 = F_18 ( V_2 -> V_18 ,
V_58 , ( unsigned long ) & V_50 ) ;
if ( ! V_51 && ( V_50 . V_59 & V_60 ) == 4 ) {
* V_11 = ( T_1 ) V_50 . V_61 . V_62 << 2 ;
return 0 ;
}
F_19 ( L_1 ) ;
return - V_63 ;
}
V_48 . V_64 = V_57 ;
V_51 = F_18 ( V_2 -> V_18 , V_65 ,
( unsigned long ) & V_48 ) ;
if ( ! V_51 && V_48 . V_66 )
* V_11 = ( T_1 ) V_48 . V_67 . V_62 << 2 ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = F_17 ( V_2 ) ;
struct V_26 V_27 ;
T_1 V_70 , V_71 ;
T_4 V_72 ;
int error = 0 ;
error = - V_63 ;
V_72 = F_21 ( V_2 , V_40 ) ;
if ( ! V_72 )
goto V_24;
if ( F_16 ( V_2 , & V_70 , & V_71 ) )
goto V_24;
error = - V_73 ;
V_69 -> V_74 = F_22 ( F_2 ( V_2 ) , V_75 ) ;
if ( ! V_69 -> V_74 )
goto V_24;
V_69 -> V_76 = F_22 ( F_2 ( V_2 ) , V_75 ) ;
if ( ! V_69 -> V_76 )
goto V_77;
V_78:
error = F_1 ( V_2 , V_70 + V_79 ,
V_69 -> V_74 , ( void * * ) & V_69 -> V_80 ,
V_81 , 0 ) ;
if ( error )
goto V_82;
error = - V_63 ;
switch ( V_69 -> V_80 -> V_83 ) {
case F_12 ( V_33 ) :
F_23 ( V_84 , & V_69 -> V_85 ) ;
case F_12 ( V_32 ) :
break;
case F_12 ( V_86 ) :
if ( ! F_11 ( V_69 -> V_80 , & V_27 ) )
goto V_82;
V_27 . V_37 >>= V_13 ;
V_70 += ( T_1 ) V_27 . V_41 +
( T_1 ) V_27 . V_44 * V_27 . V_37 ;
V_71 = ( T_1 ) V_27 . V_45 * V_27 . V_37 ;
goto V_78;
default:
if ( F_24 ( V_2 , & V_70 , & V_71 ) )
goto V_82;
goto V_78;
}
error = F_1 ( V_2 , V_70 + V_71 - 2 ,
V_69 -> V_76 ,
( void * * ) & V_69 -> V_87 , V_81 ,
0 ) ;
if ( error )
goto V_82;
error = - V_63 ;
if ( V_69 -> V_87 -> V_83 != V_69 -> V_80 -> V_83 ) {
F_25 ( L_2 ) ;
goto V_82;
}
V_72 = F_14 ( V_69 -> V_80 -> V_72 ) ;
if ( V_72 < V_40 || ( ( V_72 - 1 ) & V_72 ) )
goto V_82;
V_69 -> V_88 = V_72 ;
V_69 -> V_89 = F_26 ( V_72 ) ;
V_72 = F_6 ( T_4 , V_69 -> V_88 , V_90 ) ;
while ( V_70 & ( ( V_72 >> V_13 ) - 1 ) )
V_72 >>= 1 ;
if ( F_27 ( V_2 , V_72 ) != V_72 ) {
F_19 ( L_3 , V_72 ) ;
goto V_82;
}
V_69 -> V_91 =
V_70 >> ( V_2 -> V_92 - V_13 ) ;
V_69 -> V_70 = V_70 ;
V_69 -> V_93 = V_71 ;
V_69 -> V_94 = V_69 -> V_89 - V_2 -> V_92 ;
return 0 ;
V_82:
F_28 ( V_69 -> V_76 ) ;
V_77:
F_28 ( V_69 -> V_74 ) ;
V_24:
return error ;
}
