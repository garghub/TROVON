static T_1
F_1 ( int V_1 , void * V_2 )
{
T_2 * V_3 = V_2 ;
T_3 * V_4 ;
unsigned long V_5 ;
unsigned char volatile V_6 ;
if ( ! V_3 )
return V_7 ;
if ( ! V_3 -> V_8 )
return V_7 ;
F_2 ( & V_3 -> V_9 , V_5 ) ;
if ( ! ( F_3 ( V_3 -> V_10 + V_11 ) & V_12 ) ) {
F_4 ( & V_3 -> V_9 , V_5 ) ;
return V_7 ;
}
V_4 = V_3 -> V_13 ;
V_6 = V_4 -> V_14 ;
V_6 |= V_4 -> V_15 ;
V_6 |= V_4 -> V_16 ;
if ( ! V_3 -> V_17 )
F_5 ( & V_3 -> V_18 ) ;
F_4 ( & V_3 -> V_9 , V_5 ) ;
return V_19 ;
}
static void
F_6 ( struct V_20 * V_21 )
{
T_2 * V_3 = F_7 ( V_21 , T_2 , V_18 ) ;
T_3 * V_4 ;
int V_22 ;
unsigned long V_5 ;
if ( V_3 -> V_23 != V_24 )
return;
V_4 = V_3 -> V_13 ;
F_2 ( & V_3 -> V_9 , V_5 ) ;
if ( V_3 -> V_17 ) {
F_4 ( & V_3 -> V_9 , V_5 ) ;
return;
}
V_3 -> V_17 = 1 ;
do {
V_22 = 0 ;
if ( ! V_4 -> V_25 ) {
if ( F_8 ( V_3 , V_4 -> V_26 , & V_4 -> V_27 , & V_4 -> V_28 ,
V_29 ) ) {
V_4 -> V_25 = 1 ;
V_22 = 1 ;
}
}
if ( V_4 -> V_30 ) {
if ( F_9 ( V_3 , V_4 -> V_31 , V_4 -> V_32 , V_4 -> V_33 ) ) {
V_4 -> V_30 = 0 ;
V_22 = 1 ;
}
}
if ( V_22 ) {
V_4 -> V_16 = 1 ;
V_4 -> V_14 = 1 ;
} else
V_3 -> V_17 = 0 ;
} while ( V_22 );
F_4 ( & V_3 -> V_9 , V_5 ) ;
}
static void
F_10 ( T_2 * V_3 )
{
unsigned long V_5 ;
unsigned char V_34 ;
F_11 ( V_3 ) ;
#ifdef F_12
F_13 ( V_3 ) ;
#endif
F_2 ( & V_3 -> V_9 , V_5 ) ;
V_34 = F_3 ( V_3 -> V_10 + V_11 ) ;
V_34 &= ~ ( V_35 | V_36 ) ;
F_14 ( V_3 -> V_10 + V_11 , V_34 ) ;
V_3 -> V_8 = 0 ;
F_14 ( V_3 -> V_10 + V_37 , V_38 ) ;
V_3 -> V_23 = V_39 ;
V_3 -> V_40 = V_41 ;
F_4 ( & V_3 -> V_9 , V_5 ) ;
}
static void
F_15 ( T_2 * V_3 , int V_42 )
{
unsigned long V_5 ;
if ( V_3 -> V_23 != V_24 ) {
V_3 -> V_40 = V_41 ;
return;
}
F_2 ( & V_3 -> V_9 , V_5 ) ;
if ( ( ( V_3 -> V_40 == V_41 ) && ! V_42 ) ||
( ( V_3 -> V_40 == V_43 ) && V_42 ) ) {
F_4 ( & V_3 -> V_9 , V_5 ) ;
return;
}
if ( V_42 )
V_3 -> V_40 = V_44 ;
else
V_3 -> V_40 = V_45 ;
F_4 ( & V_3 -> V_9 , V_5 ) ;
F_5 ( & V_3 -> V_18 ) ;
}
static int
F_16 ( T_2 * V_3 )
{
T_3 * V_4 = V_3 -> V_13 ;
memset ( V_4 -> V_46 , 0 , sizeof( V_4 -> V_46 ) ) ;
V_4 -> V_16 = 1 ;
memcpy ( & V_4 -> V_26 [ V_29 - sizeof( V_47 ) ] , V_47 ,
sizeof( V_47 ) ) ;
if ( memcmp ( & V_4 -> V_26 [ V_29 - sizeof( V_47 ) ] , V_47 ,
sizeof( V_47 ) ) )
return ( - 1 ) ;
memcpy ( & V_4 -> V_31 [ V_48 - sizeof( V_47 ) ] , V_47 ,
sizeof( V_47 ) ) ;
if ( memcmp ( & V_4 -> V_31 [ V_48 - sizeof( V_47 ) ] , V_47 ,
sizeof( V_47 ) ) )
return ( - 1 ) ;
return ( 0 ) ;
}
static int
F_17 ( struct V_49 * V_3 , unsigned char * V_50 ,
unsigned long V_51 )
{
unsigned char * V_52 ;
T_3 * V_13 ;
int V_53 = ( V_54 >> 2 ) ;
if ( V_3 -> V_55 & V_56 )
F_18 ( V_3 , L_1 , V_51 ) ;
V_52 = V_3 -> V_13 ;
V_52 += ( V_51 + V_57 ) ;
while ( V_53 -- ) {
* V_52 ++ = * ( V_50 + 1 ) ;
* V_52 ++ = * V_50 ;
V_52 += 2 ;
V_50 += 2 ;
}
if ( V_51 ) {
memset ( V_3 -> V_13 , 0 , V_57 ) ;
V_13 = V_3 -> V_13 ;
V_13 -> V_58 = 0xFF ;
while ( ! V_13 -> V_58 ) ;
F_14 ( V_3 -> V_10 + V_37 , V_59 ) ;
F_19 ( 20 ) ;
if ( ( ( V_60 * ) V_3 -> V_13 ) -> V_61 != V_62 ) {
if ( V_3 -> V_55 & V_56 )
F_18 ( V_3 , L_2 ) ;
return ( - V_63 ) ;
}
}
return ( 0 ) ;
}
static int
F_20 ( struct V_49 * V_3 , unsigned char * V_50 , int V_64 )
{
V_60 * V_65 = ( V_60 * ) V_3 -> V_13 ;
unsigned char * V_52 ;
unsigned char V_66 ;
int V_67 ;
unsigned char V_68 ;
unsigned char V_69 ;
int V_70 ;
if ( V_3 -> V_55 & V_56 )
F_18 ( V_3 , L_3 , V_64 ) ;
V_52 = V_65 -> V_71 ;
V_66 = V_65 -> V_61 ;
V_69 = V_65 -> V_72 ;
V_70 = 0x1000 ;
while ( V_64 ) {
do {
V_68 = V_65 -> V_73 ;
V_70 -- ;
} while ( V_70 && ( V_68 != V_65 -> V_73 ) );
if ( ! V_70 ) {
if ( V_3 -> V_55 & V_56 )
F_18 ( V_3 , L_4 ) ;
return ( - V_74 ) ;
}
if ( ( V_67 = V_68 - V_69 - 1 ) < 0 )
V_67 += V_66 ;
if ( ! V_67 )
continue;
if ( V_67 > V_64 )
V_67 = V_64 ;
V_70 = 0x1000 ;
V_64 -= V_67 ;
while ( V_67 -- ) {
* ( V_52 + V_69 ) = * V_50 ++ ;
if ( ++ V_69 >= V_66 )
V_69 = 0 ;
V_65 -> V_72 = V_69 ;
}
}
return ( 0 ) ;
}
static int
F_21 ( struct V_49 * V_3 )
{
T_3 * V_4 = V_3 -> V_13 ;
int V_75 = 10000 / 50 ;
unsigned long V_5 ;
int V_76 ;
int V_70 ;
if ( V_3 -> V_55 & V_56 )
F_18 ( V_3 , L_5 ) ;
while ( V_75 -- ) {
if ( V_4 -> V_30 ) {
if ( ( V_4 -> V_33 != V_77 ) ||
( V_4 -> V_32 < V_78 ) ||
( V_4 -> V_32 > V_79 ) ||
( ( * ( unsigned long * ) V_4 -> V_31 ) != V_80 ) )
break;
V_76 = V_4 -> V_32 - V_81 ;
if ( V_76 > 0 )
if ( F_22 ( V_3 , V_4 -> V_31 + V_81 , V_76 ) )
break;
if ( V_3 -> V_55 & V_82 )
F_18 ( V_3 , L_6 ) ;
F_2 ( & V_3 -> V_9 , V_5 ) ;
V_3 -> V_23 = V_24 ;
F_14 ( V_3 -> V_10 + V_11 ,
F_3 ( V_3 -> V_10 + V_11 ) |
( V_35 | V_36 ) ) ;
V_3 -> V_8 = 1 ;
V_4 -> V_30 = 0 ;
V_4 -> V_16 = 1 ;
V_4 -> V_14 = 1 ;
F_4 ( & V_3 -> V_9 , V_5 ) ;
if ( ( V_83 & ( 1 << V_3 -> V_84 ) )
&& ( V_70 = F_23 ( V_3 ) ) )
{
F_10 ( V_3 ) ;
V_3 -> V_23 = V_85 ;
return ( V_70 ) ;
}
#ifdef F_12
if( ( V_70 = F_24 ( V_3 ) ) ) {
F_25 ( V_86 L_7 ) ;
}
#endif
return ( 0 ) ;
}
F_19 ( 50 ) ;
}
if ( V_3 -> V_55 & V_56 )
F_18 ( V_3 , L_8 ) ;
return ( - V_87 ) ;
}
static void
F_26 ( T_2 * V_3 )
{
F_10 ( V_3 ) ;
F_27 ( V_3 -> V_88 , V_3 ) ;
F_28 ( V_3 -> V_10 + V_11 , 1 ) ;
F_28 ( V_3 -> V_10 + V_37 , 1 ) ;
F_29 ( V_3 -> V_13 ) ;
V_3 -> V_13 = NULL ;
}
int
F_30 ( T_2 * V_3 )
{
if ( ! F_31 ( V_3 -> V_10 + V_11 , 1 , L_9 ) )
return ( - 1 ) ;
if ( ! F_31 ( V_3 -> V_10 + V_37 , 1 , L_9 ) ) {
F_28 ( V_3 -> V_10 + V_11 , 1 ) ;
return ( - 1 ) ;
}
V_3 -> V_89 = V_3 -> V_90 + V_91 - 1 ;
if ( ! ( V_3 -> V_13 = F_32 ( V_3 -> V_90 , V_91 ) ) ) {
F_28 ( V_3 -> V_10 + V_11 , 1 ) ;
F_28 ( V_3 -> V_10 + V_37 , 1 ) ;
return ( - 1 ) ;
}
F_10 ( V_3 ) ;
if ( F_33 ( V_3 -> V_88 , F_1 , V_92 , L_9 , V_3 ) ) {
F_26 ( V_3 ) ;
return ( - 1 ) ;
}
V_3 -> V_93 = F_10 ;
V_3 -> V_94 = F_26 ;
V_3 -> V_95 = F_16 ;
V_3 -> V_96 = F_17 ;
V_3 -> V_97 = F_20 ;
V_3 -> V_98 = F_21 ;
V_3 -> V_99 = F_15 ;
F_34 ( & V_3 -> V_18 , F_6 ) ;
F_35 ( & V_3 -> V_9 ) ;
return ( 0 ) ;
}
