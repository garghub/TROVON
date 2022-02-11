static void T_1 F_1 ( T_2 V_1 ,
unsigned long V_2 , bool V_3 )
{
void * V_4 , * V_5 ;
T_3 V_6 ;
if ( ! V_7 )
return;
F_2 () ;
F_3 () ;
while ( V_2 ) {
V_6 = F_4 ( T_3 , sizeof( V_8 ) , V_2 ) ;
V_4 = V_3 ? F_5 ( V_1 , V_6 ) :
F_6 ( V_1 , V_6 ) ;
V_5 = V_3 ? F_7 ( V_1 , V_6 ) :
F_8 ( V_1 , V_6 ) ;
F_9 ( ! V_4 || ! V_5 ) ;
memcpy ( V_8 , V_4 , V_6 ) ;
memcpy ( V_5 , V_8 , V_6 ) ;
F_10 ( V_5 , V_6 ) ;
F_10 ( V_4 , V_6 ) ;
V_1 += V_6 ;
V_2 -= V_6 ;
}
}
void T_1 F_11 ( T_2 V_1 , unsigned long V_2 )
{
F_1 ( V_1 , V_2 , true ) ;
}
void T_1 F_12 ( T_2 V_1 , unsigned long V_2 )
{
F_1 ( V_1 , V_2 , false ) ;
}
static void T_1 F_13 ( void * V_9 , unsigned long V_2 ,
bool V_10 )
{
unsigned long V_1 = ( unsigned long ) V_9 - V_11 ;
T_4 V_12 , V_13 ;
V_12 = F_14 ( V_14 ) ;
do {
V_13 = V_10 ? ( V_1 & V_15 ) + V_12 : 0 ;
F_15 ( ( unsigned long ) V_9 , V_13 ) ;
V_9 += V_16 ;
V_1 += V_16 ;
V_2 = ( V_2 <= V_16 ) ? 0 : V_2 - V_16 ;
} while ( V_2 );
F_16 () ;
}
void T_1 F_17 ( char * V_17 )
{
struct V_18 * V_19 ;
unsigned long V_20 ;
if ( ! F_18 () )
return;
V_19 = (struct V_18 * ) V_17 ;
V_20 = V_19 -> V_21 . V_22 | ( ( V_23 ) V_19 -> V_24 << 32 ) ;
F_13 ( V_17 , sizeof( V_18 ) , false ) ;
if ( ! V_20 )
return;
F_13 ( F_19 ( V_20 ) , V_25 , false ) ;
}
void T_1 F_20 ( char * V_17 )
{
struct V_18 * V_19 ;
unsigned long V_20 ;
if ( ! F_18 () )
return;
F_13 ( V_17 , sizeof( V_18 ) , true ) ;
V_19 = (struct V_18 * ) V_17 ;
V_20 = V_19 -> V_21 . V_22 | ( ( V_23 ) V_19 -> V_24 << 32 ) ;
if ( ! V_20 )
return;
F_13 ( F_19 ( V_20 ) , V_25 , true ) ;
}
void T_1 F_21 ( void )
{
unsigned int V_26 ;
if ( ! V_7 )
return;
V_14 = F_22 ( V_14 ) ;
V_27 = F_22 ( V_27 ) ;
for ( V_26 = 0 ; V_26 < F_23 ( V_28 ) ; V_26 ++ )
V_28 [ V_26 ] = F_24 ( V_28 [ V_26 ] ) ;
}
void T_1 F_25 ( void )
{
if ( ! V_7 )
return;
F_26 () ;
F_27 ( L_1 ) ;
}
void F_28 ( void * V_9 , unsigned long V_2 )
{
F_29 ( F_30 ( V_2 ) != V_2 ,
L_2 , V_2 ) ;
F_31 ( ( unsigned long ) V_9 , V_2 >> V_29 ) ;
}
static void T_1 F_32 ( T_5 * V_30 , unsigned long V_31 ,
unsigned long V_32 )
{
unsigned long V_33 , V_34 , V_35 ;
T_5 * V_36 ;
V_33 = V_31 & V_37 ;
V_34 = V_32 & V_37 ;
V_35 = ( ( ( V_34 - V_33 ) / V_38 ) + 1 ) ;
V_35 *= sizeof( T_5 ) ;
V_36 = V_30 + F_33 ( V_31 ) ;
memset ( V_36 , 0 , V_35 ) ;
}
static void T_1 * F_34 ( T_5 * V_30 , void * V_39 ,
unsigned long V_9 , T_4 V_40 )
{
T_5 * V_36 ;
T_6 * V_41 ;
T_7 * V_42 ;
T_8 * V_43 ;
V_36 = V_30 + F_33 ( V_9 ) ;
if ( F_35 ( * V_36 ) ) {
if ( F_36 ( V_44 ) )
V_41 = ( T_6 * ) ( F_35 ( * V_36 ) & ~ V_45 ) ;
else
V_42 = ( T_7 * ) ( F_35 ( * V_36 ) & ~ V_45 ) ;
} else {
T_5 V_46 ;
if ( F_36 ( V_44 ) ) {
V_41 = V_39 ;
memset ( V_41 , 0 , sizeof( * V_41 ) * V_47 ) ;
V_39 += sizeof( * V_41 ) * V_47 ;
V_46 = F_37 ( ( V_48 ) V_41 + V_49 ) ;
} else {
V_42 = V_39 ;
memset ( V_42 , 0 , sizeof( * V_42 ) * V_50 ) ;
V_39 += sizeof( * V_42 ) * V_50 ;
V_46 = F_37 ( ( V_48 ) V_42 + V_49 ) ;
}
F_38 ( V_36 , V_46 ) ;
}
if ( F_36 ( V_44 ) ) {
V_41 += F_39 ( V_9 ) ;
if ( F_40 ( * V_41 ) ) {
V_42 = ( T_7 * ) ( F_40 ( * V_41 ) & ~ V_45 ) ;
} else {
T_6 V_51 ;
V_42 = V_39 ;
memset ( V_42 , 0 , sizeof( * V_42 ) * V_50 ) ;
V_39 += sizeof( * V_42 ) * V_50 ;
V_51 = F_41 ( ( V_52 ) V_42 + V_53 ) ;
F_42 ( V_41 , V_51 ) ;
}
}
V_42 += F_43 ( V_9 ) ;
if ( F_44 ( * V_42 ) ) {
if ( F_44 ( * V_42 ) & V_54 )
goto V_55;
V_43 = ( T_8 * ) ( F_44 ( * V_42 ) & ~ V_45 ) ;
} else {
T_7 V_56 ;
V_43 = V_39 ;
memset ( V_43 , 0 , sizeof( * V_43 ) * V_57 ) ;
V_39 += sizeof( * V_43 ) * V_57 ;
V_56 = F_45 ( ( T_4 ) V_43 + V_58 ) ;
F_46 ( V_42 , V_56 ) ;
}
V_43 += F_47 ( V_9 ) ;
if ( ! F_48 ( * V_43 ) || ! ( F_48 ( * V_43 ) & V_54 ) )
F_49 ( V_43 , F_50 ( V_40 ) ) ;
V_55:
return V_39 ;
}
static unsigned long T_1 F_51 ( unsigned long V_6 )
{
unsigned long V_59 , V_60 , V_61 ;
unsigned long V_62 ;
if ( F_36 ( V_44 ) ) {
V_59 = ( F_52 ( V_6 , V_38 ) / V_38 ) + 1 ;
V_59 *= sizeof( T_6 ) * V_47 ;
V_60 = ( F_52 ( V_6 , V_63 ) / V_63 ) + 1 ;
V_60 *= sizeof( T_7 ) * V_50 ;
} else {
V_59 = 0 ;
V_60 = ( F_52 ( V_6 , V_38 ) / V_38 ) + 1 ;
V_60 *= sizeof( T_7 ) * V_50 ;
}
V_61 = ( F_52 ( V_6 , V_64 ) / V_64 ) + 1 ;
V_61 *= sizeof( T_8 ) * V_57 ;
V_62 = V_59 + V_60 + V_61 ;
if ( F_36 ( V_44 ) ) {
V_59 = F_52 ( V_62 , V_38 ) / V_38 ;
V_59 *= sizeof( T_6 ) * V_47 ;
V_60 = F_52 ( V_62 , V_63 ) / V_63 ;
V_60 *= sizeof( T_7 ) * V_50 ;
} else {
V_59 = 0 ;
V_60 = F_52 ( V_62 , V_38 ) / V_38 ;
V_60 *= sizeof( T_7 ) * V_50 ;
}
V_61 = F_52 ( V_62 , V_64 ) / V_64 ;
V_61 *= sizeof( T_8 ) * V_57 ;
V_62 += V_59 + V_60 + V_61 ;
return V_62 ;
}
void T_1 F_53 ( void )
{
unsigned long V_65 , V_66 , V_67 ;
unsigned long V_68 , V_69 , V_70 ;
unsigned long V_71 , V_72 , V_73 ;
unsigned long V_74 ;
unsigned long V_1 , V_12 ;
unsigned long V_75 ;
void * V_39 ;
T_5 * V_46 ;
if ( ! F_18 () )
return;
V_71 = F_54 ( V_76 ) ;
V_72 = F_52 ( F_54 ( V_77 ) , V_78 ) ;
V_73 = V_72 - V_71 ;
V_65 = V_72 ;
V_68 = V_65 ;
V_69 = V_68 + ( V_79 * 2 ) + V_78 ;
V_70 = V_69 - V_68 ;
V_74 = sizeof( T_5 ) * V_80 ;
V_74 += F_51 ( V_69 - V_71 ) * 2 ;
V_74 += F_51 ( V_70 + V_74 ) ;
V_67 = V_70 + V_74 ;
V_66 = V_65 + V_67 ;
V_39 = ( void * ) V_69 ;
V_46 = ( T_5 * ) F_55 () ;
V_1 = V_65 ;
while ( V_1 < V_66 ) {
V_39 = F_34 ( V_46 , V_39 ,
V_1 ,
V_1 + V_81 ) ;
V_1 += V_78 ;
}
F_56 ( F_57 () ) ;
V_46 = V_39 ;
memset ( V_46 , 0 , sizeof( * V_46 ) * V_80 ) ;
V_39 += sizeof( * V_46 ) * V_80 ;
V_12 = V_81 | V_82 ;
V_1 = V_71 ;
while ( V_1 < V_72 ) {
V_39 = F_34 ( V_46 , V_39 ,
V_1 ,
V_1 + V_12 ) ;
V_1 += V_78 ;
}
V_75 = ( F_33 ( V_66 ) + 1 ) & ( V_80 - 1 ) ;
V_75 <<= V_83 ;
V_12 = ( V_81 & ~ V_84 ) | ( V_85 | V_86 ) ;
V_1 = V_71 ;
while ( V_1 < V_72 ) {
V_39 = F_34 ( V_46 , V_39 ,
V_1 + V_75 ,
V_1 + V_12 ) ;
V_1 += V_78 ;
}
V_1 = V_65 ;
while ( V_1 < V_66 ) {
V_39 = F_34 ( V_46 , V_39 ,
V_1 ,
V_1 + V_81 ) ;
V_39 = F_34 ( V_46 , V_39 ,
V_1 + V_75 ,
V_1 + V_81 ) ;
V_1 += V_78 ;
}
F_58 ( V_71 , V_71 + V_75 ,
V_73 , V_65 , ( unsigned long ) V_46 ) ;
F_32 ( V_46 , V_71 + V_75 ,
V_72 + V_75 ) ;
F_32 ( V_46 , V_65 + V_75 ,
V_66 + V_75 ) ;
F_56 ( F_57 () ) ;
}
void T_1 T_9 F_59 ( struct V_18 * V_87 )
{
const char * V_88 , * V_89 , * V_90 , * V_91 ;
unsigned int V_92 , V_93 , V_94 , V_95 ;
bool V_96 ;
unsigned long V_97 ;
char V_98 [ 16 ] ;
V_23 V_99 ;
V_92 = 0x80000000 ;
V_94 = 0 ;
F_60 ( & V_92 , & V_93 , & V_94 , & V_95 ) ;
if ( V_92 < 0x8000001f )
return;
V_92 = 0x8000001f ;
V_94 = 0 ;
F_60 ( & V_92 , & V_93 , & V_94 , & V_95 ) ;
if ( ! ( V_92 & 1 ) )
return;
V_97 = 1UL << ( V_93 & 0x3f ) ;
V_99 = F_61 ( V_100 ) ;
if ( ! ( V_99 & V_101 ) )
return;
asm ("lea sme_cmdline_arg(%%rip), %0"
: "=r" (cmdline_arg)
: "p" (sme_cmdline_arg));
asm ("lea sme_cmdline_on(%%rip), %0"
: "=r" (cmdline_on)
: "p" (sme_cmdline_on));
asm ("lea sme_cmdline_off(%%rip), %0"
: "=r" (cmdline_off)
: "p" (sme_cmdline_off));
if ( F_36 ( V_102 ) )
V_96 = true ;
else
V_96 = false ;
V_88 = ( const char * ) ( ( V_23 ) V_87 -> V_21 . V_22 |
( ( V_23 ) V_87 -> V_24 << 32 ) ) ;
F_62 ( V_88 , V_89 , V_98 , sizeof( V_98 ) ) ;
if ( ! strncmp ( V_98 , V_90 , sizeof( V_98 ) ) )
V_7 = V_97 ;
else if ( ! strncmp ( V_98 , V_91 , sizeof( V_98 ) ) )
V_7 = 0 ;
else
V_7 = V_96 ? V_97 : 0 ;
}
