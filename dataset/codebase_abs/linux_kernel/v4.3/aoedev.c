static int
F_1 ( T_1 * V_1 )
{
T_1 V_2 ;
T_1 V_3 ;
int error = 0 ;
F_2 ( & V_4 , V_2 ) ;
V_3 = F_3 ( V_5 , V_6 ) ;
if ( V_3 < V_6 )
F_4 ( V_3 , V_5 ) ;
else
error = - 1 ;
F_5 ( & V_4 , V_2 ) ;
* V_1 = V_3 * V_7 ;
return error ;
}
static int
F_6 ( T_1 * V_1 , T_1 V_8 , int V_9 )
{
T_1 V_2 ;
T_1 V_3 ;
int error = 0 ;
enum {
V_10 = 16 ,
};
if ( V_9 >= V_10 ) {
F_7 ( L_1 ,
L_2 ,
V_10 ) ;
error = - 1 ;
goto V_11;
}
V_3 = V_8 * V_10 + V_9 ;
if ( V_3 >= V_6 ) {
F_7 ( L_3 ,
L_4 ,
V_8 , V_9 ) ;
error = - 1 ;
goto V_11;
}
F_2 ( & V_4 , V_2 ) ;
if ( F_8 ( V_3 , V_5 ) ) {
F_7 ( L_5 ,
L_6 ,
V_3 ) ;
error = - 1 ;
} else
F_4 ( V_3 , V_5 ) ;
F_5 ( & V_4 , V_2 ) ;
* V_1 = V_3 * V_7 ;
V_11:
return error ;
}
static int
F_9 ( T_1 * V_1 , T_1 V_8 , int V_9 )
{
if ( V_12 )
return F_1 ( V_1 ) ;
else
return F_6 ( V_1 , V_8 , V_9 ) ;
}
static void
F_10 ( T_1 V_13 )
{
T_1 V_2 ;
V_13 /= V_7 ;
F_11 ( V_13 >= V_6 ) ;
F_2 ( & V_4 , V_2 ) ;
F_11 ( ! F_8 ( V_13 , V_5 ) ) ;
F_12 ( V_13 , V_5 ) ;
F_5 ( & V_4 , V_2 ) ;
}
void
F_13 ( struct V_14 * V_15 )
{
T_1 V_2 ;
F_2 ( & V_16 , V_2 ) ;
V_15 -> V_17 -- ;
F_5 ( & V_16 , V_2 ) ;
}
static void
F_14 ( T_1 V_18 )
{
struct V_14 * V_15 ;
V_15 = (struct V_14 * ) V_18 ;
if ( V_15 -> V_2 & V_19 )
return;
V_15 -> V_20 . V_21 = V_22 + V_23 ;
F_15 ( & V_15 -> V_20 ) ;
}
static void
F_16 ( struct V_14 * V_15 )
{
struct V_24 * V_25 ;
struct V_26 * V_26 ;
unsigned long V_3 ;
F_17 ( V_15 , V_15 -> V_27 . V_28 ) ;
V_25 = V_15 -> V_27 . V_25 ;
if ( V_25 == NULL )
return;
while ( ( V_26 = V_15 -> V_27 . V_29 ) ) {
V_26 -> V_30 = - V_31 ;
V_15 -> V_27 . V_29 = V_26 -> V_32 ;
V_3 = ( unsigned long ) V_25 -> V_33 ;
V_25 -> V_33 = ( void * ) -- V_3 ;
}
if ( ( unsigned long ) V_25 -> V_33 == 0 )
F_18 ( V_15 , V_25 , 0 ) ;
}
static void
F_19 ( struct V_34 * V_35 )
{
struct V_36 * V_37 ;
V_37 = F_20 ( V_35 , struct V_36 , V_38 ) ;
F_21 ( V_35 ) ;
if ( V_37 -> V_28 ) {
V_37 -> V_28 -> V_39 -- ;
F_17 ( V_37 -> V_40 -> V_15 , V_37 -> V_28 ) ;
}
F_22 ( V_37 ) ;
}
void
F_23 ( struct V_14 * V_15 )
{
struct V_41 * V_40 , * * V_42 , * * V_43 ;
struct V_34 * V_38 , * V_35 , * V_44 ;
struct V_24 * V_25 ;
int V_45 ;
V_15 -> V_2 &= ~ V_46 ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
V_38 = & V_15 -> V_48 [ V_45 ] ;
F_24 (pos, nx, head)
F_19 ( V_35 ) ;
}
V_38 = & V_15 -> V_49 ;
F_24 (pos, nx, head)
F_19 ( V_35 ) ;
V_42 = V_15 -> V_50 ;
V_43 = V_42 + V_15 -> V_51 ;
for (; V_42 < V_43 && ( V_40 = * V_42 ) ; V_42 ++ ) {
F_25 ( V_40 ) ;
V_40 -> V_52 = 0 ;
}
F_16 ( V_15 ) ;
if ( V_15 -> V_53 ) {
while ( ( V_25 = F_26 ( V_15 -> V_53 ) ) ) {
F_27 ( V_25 ) ;
F_18 ( V_15 , V_25 , 1 ) ;
}
}
if ( V_15 -> V_54 )
F_28 ( V_15 -> V_54 , 0 ) ;
}
static int
F_29 ( char * V_55 , T_2 V_56 , struct V_14 * V_15 )
{
const char * V_57 ;
T_2 V_58 ;
if ( ! V_15 -> V_54 )
return 0 ;
V_57 = F_30 ( V_15 -> V_54 -> V_59 ) ;
V_58 = sizeof( V_15 -> V_54 -> V_59 ) ;
V_58 -= V_57 - V_15 -> V_54 -> V_59 ;
if ( V_56 < V_58 )
V_58 = V_56 ;
return ! strncmp ( V_55 , V_57 , V_58 ) ;
}
static void
F_31 ( struct V_14 * V_15 )
{
struct V_41 * * V_40 , * * V_60 ;
int V_61 = 0 ;
unsigned long V_2 ;
F_2 ( & V_15 -> V_62 , V_2 ) ;
if ( V_15 -> V_2 & V_19
&& ! ( V_15 -> V_2 & V_63 ) ) {
V_15 -> V_2 |= V_63 ;
V_61 = 1 ;
}
F_5 ( & V_15 -> V_62 , V_2 ) ;
if ( ! V_61 )
return;
F_32 ( & V_15 -> V_20 ) ;
if ( V_15 -> V_54 ) {
F_33 ( V_15 ) ;
F_34 ( V_15 ) ;
F_35 ( V_15 -> V_54 ) ;
F_36 ( V_15 -> V_54 ) ;
F_37 ( V_15 -> V_53 ) ;
}
V_40 = V_15 -> V_50 ;
V_60 = V_40 + V_15 -> V_51 ;
for (; V_40 < V_60 && * V_40 ; V_40 ++ )
F_38 ( V_15 , * V_40 ) ;
if ( V_15 -> V_64 )
F_39 ( V_15 -> V_64 ) ;
F_40 ( V_15 ) ;
F_10 ( V_15 -> V_1 ) ;
F_2 ( & V_15 -> V_62 , V_2 ) ;
V_15 -> V_2 |= V_65 ;
F_5 ( & V_15 -> V_62 , V_2 ) ;
}
static int
F_41 ( const char T_3 * V_66 , T_2 V_67 , int V_68 )
{
T_1 V_2 ;
struct V_14 * V_15 , * * V_69 ;
char V_28 [ 16 ] ;
int V_70 = 0 ;
int V_71 = 0 ;
unsigned int V_72 ;
V_72 = V_73 | V_74 | V_19 ;
if ( ! V_68 && V_67 >= 3 ) {
if ( V_67 > sizeof V_28 )
V_67 = sizeof V_28 ;
if ( F_42 ( V_28 , V_66 , V_67 ) )
return - V_75 ;
V_70 = ! strncmp ( V_28 , L_7 , 3 ) ;
if ( ! V_70 )
V_71 = 1 ;
}
F_43 () ;
F_2 ( & V_16 , V_2 ) ;
for ( V_15 = V_76 ; V_15 ; V_15 = V_15 -> V_77 ) {
F_44 ( & V_15 -> V_62 ) ;
if ( V_68 ) {
} else if ( V_71 ) {
if ( ! F_29 ( V_28 , V_67 , V_15 ) )
goto V_78;
} else if ( ( ! V_70 && ( V_15 -> V_2 & V_46 ) )
|| V_15 -> V_2 & V_72
|| V_15 -> V_79
|| V_15 -> V_17 )
goto V_78;
F_23 ( V_15 ) ;
V_15 -> V_2 |= V_19 ;
V_78:
F_45 ( & V_15 -> V_62 ) ;
}
F_5 ( & V_16 , V_2 ) ;
V_80:
F_2 ( & V_16 , V_2 ) ;
for ( V_15 = V_76 ; V_15 ; V_15 = V_15 -> V_77 ) {
F_44 ( & V_15 -> V_62 ) ;
if ( V_15 -> V_2 & V_19
&& ! ( V_15 -> V_2 & V_63 ) ) {
F_45 ( & V_15 -> V_62 ) ;
F_5 ( & V_16 , V_2 ) ;
F_31 ( V_15 ) ;
goto V_80;
}
F_45 ( & V_15 -> V_62 ) ;
}
for ( V_69 = & V_76 , V_15 = * V_69 ; V_15 ; V_15 = * V_69 ) {
struct V_14 * V_81 = NULL ;
F_44 ( & V_15 -> V_62 ) ;
if ( V_15 -> V_2 & V_65 ) {
* V_69 = V_15 -> V_77 ;
V_81 = V_15 ;
} else {
V_69 = & V_15 -> V_77 ;
}
F_45 ( & V_15 -> V_62 ) ;
if ( V_81 )
F_46 ( V_81 -> V_50 ) ;
F_46 ( V_81 ) ;
}
F_5 ( & V_16 , V_2 ) ;
return 0 ;
}
int
F_47 ( const char T_3 * V_66 , T_2 V_67 )
{
return F_41 ( V_66 , V_67 , V_82 ) ;
}
static void
F_48 ( struct V_83 * V_84 )
{
enum { V_85 = 250 , V_86 = 30 * 1000 };
int V_45 = V_86 / V_85 ;
if ( V_84 == NULL )
return;
while ( F_49 ( & F_50 ( V_84 ) -> V_87 ) != 1 && V_45 -- > 0 )
F_51 ( V_85 ) ;
if ( V_45 < 0 ) {
F_52 ( V_88
L_8 ,
V_84 -> V_89 ? V_84 -> V_89 -> V_90 : L_9 ,
L_10 ) ;
return;
}
V_84 -> V_91 -= V_84 -> V_92 ;
F_50 ( V_84 ) -> V_93 = V_84 -> V_92 = 0 ;
F_53 ( V_84 , 0 ) ;
F_54 ( V_84 ) ;
}
static void
F_40 ( struct V_14 * V_15 )
{
struct V_83 * V_84 , * V_94 ;
F_55 (&d->skbpool, skb, tmp)
F_48 ( V_84 ) ;
F_56 ( & V_15 -> V_95 ) ;
}
struct V_14 *
F_57 ( T_1 V_96 , int V_97 , int V_98 )
{
struct V_14 * V_15 ;
int V_45 ;
T_1 V_2 ;
T_1 V_1 = 0 ;
F_2 ( & V_16 , V_2 ) ;
for ( V_15 = V_76 ; V_15 ; V_15 = V_15 -> V_77 )
if ( V_15 -> V_99 == V_96 && V_15 -> V_100 == V_97 ) {
F_44 ( & V_15 -> V_62 ) ;
if ( V_15 -> V_2 & V_19 ) {
F_45 ( & V_15 -> V_62 ) ;
V_15 = NULL ;
goto V_11;
}
V_15 -> V_17 ++ ;
F_45 ( & V_15 -> V_62 ) ;
break;
}
if ( V_15 || ! V_98 || F_9 ( & V_1 , V_96 , V_97 ) < 0 )
goto V_11;
V_15 = F_58 ( 1 , sizeof *V_15 , V_101 ) ;
if ( ! V_15 )
goto V_11;
V_15 -> V_50 = F_58 ( V_102 , sizeof( * V_15 -> V_50 ) , V_101 ) ;
if ( ! V_15 -> V_50 ) {
F_46 ( V_15 ) ;
V_15 = NULL ;
goto V_11;
}
V_15 -> V_51 = V_102 ;
F_59 ( & V_15 -> V_103 , V_104 ) ;
F_60 ( & V_15 -> V_62 ) ;
F_61 ( & V_15 -> V_95 ) ;
F_62 ( & V_15 -> V_20 ) ;
V_15 -> V_20 . V_105 = ( T_1 ) V_15 ;
V_15 -> V_20 . V_106 = F_14 ;
V_15 -> V_20 . V_21 = V_22 + V_23 ;
F_15 ( & V_15 -> V_20 ) ;
V_15 -> V_64 = NULL ;
V_15 -> V_107 = V_15 -> V_50 ;
V_15 -> V_17 = 1 ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ )
F_63 ( & V_15 -> V_48 [ V_45 ] ) ;
F_63 ( & V_15 -> V_49 ) ;
V_15 -> V_1 = V_1 ;
V_15 -> V_99 = V_96 ;
V_15 -> V_100 = V_97 ;
V_15 -> V_108 = V_109 ;
V_15 -> V_110 = V_111 ;
V_15 -> V_77 = V_76 ;
V_76 = V_15 ;
V_11:
F_5 ( & V_16 , V_2 ) ;
return V_15 ;
}
static void
F_38 ( struct V_14 * V_15 , struct V_41 * V_40 )
{
struct V_36 * V_37 ;
struct V_34 * V_35 , * V_44 , * V_38 ;
struct V_112 * V_113 ;
for ( V_113 = V_40 -> V_114 ; V_113 < & V_40 -> V_114 [ V_115 ] ; ++ V_113 ) {
if ( ! V_113 -> V_116 )
break;
F_64 ( V_113 -> V_116 ) ;
}
V_38 = & V_40 -> V_117 ;
F_24 (pos, nx, head) {
F_21 ( V_35 ) ;
V_37 = F_20 ( V_35 , struct V_36 , V_38 ) ;
F_48 ( V_37 -> V_84 ) ;
F_46 ( V_37 ) ;
}
F_46 ( V_40 ) ;
}
void
F_65 ( void )
{
F_43 () ;
F_41 ( NULL , 0 , V_118 ) ;
}
int T_4
F_66 ( void )
{
return 0 ;
}
