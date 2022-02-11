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
V_3 = V_8 * V_10 + V_9 ;
if ( V_9 >= V_10 || V_3 >= V_6 ) {
F_7 ( L_1 ,
L_2 ,
V_8 , V_9 ) ;
error = - 1 ;
} else {
F_2 ( & V_4 , V_2 ) ;
if ( F_8 ( V_3 , V_5 ) ) {
F_7 ( L_3 ,
L_4 ,
V_3 ) ;
error = - 1 ;
} else
F_4 ( V_3 , V_5 ) ;
F_5 ( & V_4 , V_2 ) ;
}
* V_1 = V_3 ;
return error ;
}
static int
F_9 ( T_1 * V_1 , T_1 V_8 , int V_9 )
{
if ( V_11 )
return F_1 ( V_1 ) ;
else
return F_6 ( V_1 , V_8 , V_9 ) ;
}
static void
F_10 ( T_1 V_12 )
{
T_1 V_2 ;
V_12 /= V_7 ;
F_11 ( V_12 >= V_6 ) ;
F_2 ( & V_4 , V_2 ) ;
F_11 ( ! F_8 ( V_12 , V_5 ) ) ;
F_12 ( V_12 , V_5 ) ;
F_5 ( & V_4 , V_2 ) ;
}
void
F_13 ( struct V_13 * V_14 )
{
T_1 V_2 ;
F_2 ( & V_15 , V_2 ) ;
V_14 -> V_16 -- ;
F_5 ( & V_15 , V_2 ) ;
}
static void
F_14 ( T_1 V_17 )
{
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) V_17 ;
if ( V_14 -> V_2 & V_18 )
return;
V_14 -> V_19 . V_20 = V_21 + V_22 ;
F_15 ( & V_14 -> V_19 ) ;
}
static void
F_16 ( struct V_13 * V_14 )
{
struct V_23 * V_24 ;
struct V_25 * V_25 ;
unsigned long V_3 ;
F_17 ( V_14 , V_14 -> V_26 . V_27 ) ;
V_24 = V_14 -> V_26 . V_24 ;
if ( V_24 == NULL )
return;
while ( ( V_25 = V_14 -> V_26 . V_28 ) ) {
F_12 ( V_29 , & V_25 -> V_30 ) ;
V_14 -> V_26 . V_28 = V_25 -> V_31 ;
V_3 = ( unsigned long ) V_24 -> V_32 ;
V_24 -> V_32 = ( void * ) -- V_3 ;
}
if ( ( unsigned long ) V_24 -> V_32 == 0 )
F_18 ( V_14 , V_24 , 0 ) ;
}
void
F_19 ( struct V_13 * V_14 )
{
struct V_33 * V_34 , * * V_35 , * * V_36 ;
struct V_37 * V_38 ;
struct V_39 * V_40 , * V_41 , * V_42 ;
struct V_23 * V_24 ;
int V_43 ;
V_14 -> V_2 &= ~ V_44 ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
V_40 = & V_14 -> V_46 [ V_43 ] ;
F_20 (pos, nx, head) {
V_38 = F_21 ( V_41 , struct V_37 , V_40 ) ;
F_22 ( V_41 ) ;
if ( V_38 -> V_27 ) {
V_38 -> V_27 -> V_47 -- ;
F_17 ( V_14 , V_38 -> V_27 ) ;
}
F_23 ( V_38 ) ;
}
}
V_35 = V_14 -> V_48 ;
V_36 = V_35 + V_49 ;
for (; V_35 < V_36 && ( V_34 = * V_35 ) ; V_35 ++ ) {
V_34 -> V_50 = V_34 -> V_51 ;
V_34 -> V_52 = 0 ;
}
F_16 ( V_14 ) ;
V_14 -> V_53 = NULL ;
if ( V_14 -> V_54 ) {
while ( ( V_24 = F_24 ( V_14 -> V_54 ) ) ) {
F_25 ( V_24 ) ;
F_18 ( V_14 , V_24 , 1 ) ;
}
}
if ( V_14 -> V_55 )
F_26 ( V_14 -> V_55 , 0 ) ;
}
static void
F_27 ( struct V_13 * V_14 )
{
struct V_33 * * V_34 , * * V_56 ;
F_28 ( & V_14 -> V_57 ) ;
if ( V_14 -> V_55 ) {
F_29 ( V_14 ) ;
F_30 ( V_14 -> V_55 ) ;
F_31 ( V_14 -> V_55 ) ;
F_32 ( V_14 -> V_54 ) ;
}
V_34 = V_14 -> V_48 ;
V_56 = V_34 + V_49 ;
for (; V_34 < V_56 && * V_34 ; V_34 ++ )
F_33 ( V_14 , * V_34 ) ;
if ( V_14 -> V_58 )
F_34 ( V_14 -> V_58 ) ;
F_35 ( V_14 ) ;
F_10 ( V_14 -> V_1 ) ;
F_36 ( V_14 ) ;
}
int
F_37 ( const char T_2 * V_59 , T_3 V_60 )
{
T_1 V_2 ;
struct V_13 * V_14 , * * V_61 ;
struct V_13 * V_62 = NULL ;
char V_27 [ 16 ] ;
int V_63 = 0 ;
if ( V_60 >= 3 ) {
if ( V_60 > sizeof V_27 )
V_60 = sizeof V_27 ;
if ( F_38 ( V_27 , V_59 , V_60 ) )
return - V_64 ;
V_63 = ! strncmp ( V_27 , L_5 , 3 ) ;
}
F_2 ( & V_15 , V_2 ) ;
V_61 = & V_65 ;
while ( ( V_14 = * V_61 ) ) {
F_39 ( & V_14 -> V_66 ) ;
if ( ( ! V_63 && ( V_14 -> V_2 & V_44 ) )
|| ( V_14 -> V_2 & ( V_67 | V_68 ) )
|| V_14 -> V_69
|| V_14 -> V_16 ) {
F_40 ( & V_14 -> V_66 ) ;
V_61 = & V_14 -> V_70 ;
continue;
}
* V_61 = V_14 -> V_70 ;
F_19 ( V_14 ) ;
V_14 -> V_2 |= V_18 ;
F_40 ( & V_14 -> V_66 ) ;
V_14 -> V_70 = V_62 ;
V_62 = V_14 ;
}
F_5 ( & V_15 , V_2 ) ;
while ( ( V_14 = V_62 ) ) {
V_62 = V_14 -> V_70 ;
F_41 ( & V_14 -> V_19 ) ;
F_27 ( V_14 ) ;
}
return 0 ;
}
static void
F_42 ( struct V_71 * V_72 )
{
enum { V_73 = 250 , V_74 = 30 * 1000 };
int V_43 = V_74 / V_73 ;
if ( V_72 == NULL )
return;
while ( F_43 ( & F_44 ( V_72 ) -> V_75 ) != 1 && V_43 -- > 0 )
F_45 ( V_73 ) ;
if ( V_43 < 0 ) {
F_46 ( V_76
L_6 ,
V_72 -> V_77 ? V_72 -> V_77 -> V_78 : L_7 ,
L_8 ) ;
return;
}
V_72 -> V_79 -= V_72 -> V_80 ;
F_44 ( V_72 ) -> V_81 = V_72 -> V_80 = 0 ;
F_47 ( V_72 , 0 ) ;
F_48 ( V_72 ) ;
}
static void
F_35 ( struct V_13 * V_14 )
{
struct V_71 * V_72 , * V_82 ;
F_49 (&d->skbpool, skb, tmp)
F_42 ( V_72 ) ;
F_50 ( & V_14 -> V_83 ) ;
}
struct V_13 *
F_51 ( T_1 V_84 , int V_85 , int V_86 )
{
struct V_13 * V_14 ;
int V_43 ;
T_1 V_2 ;
T_1 V_1 ;
F_2 ( & V_15 , V_2 ) ;
for ( V_14 = V_65 ; V_14 ; V_14 = V_14 -> V_70 )
if ( V_14 -> V_87 == V_84 && V_14 -> V_88 == V_85 ) {
V_14 -> V_16 ++ ;
break;
}
if ( V_14 || ! V_86 || F_9 ( & V_1 , V_84 , V_85 ) < 0 )
goto V_89;
V_14 = F_52 ( 1 , sizeof *V_14 , V_90 ) ;
if ( ! V_14 )
goto V_89;
F_53 ( & V_14 -> V_57 , V_91 ) ;
F_54 ( & V_14 -> V_66 ) ;
F_55 ( & V_14 -> V_83 ) ;
F_56 ( & V_14 -> V_19 ) ;
V_14 -> V_19 . V_92 = ( T_1 ) V_14 ;
V_14 -> V_19 . V_93 = F_14 ;
V_14 -> V_19 . V_20 = V_21 + V_22 ;
F_15 ( & V_14 -> V_19 ) ;
V_14 -> V_58 = NULL ;
V_14 -> V_94 = V_14 -> V_48 ;
V_14 -> V_16 = 1 ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ )
F_57 ( & V_14 -> V_46 [ V_43 ] ) ;
V_14 -> V_1 = V_1 ;
V_14 -> V_87 = V_84 ;
V_14 -> V_88 = V_85 ;
V_14 -> V_95 = V_96 ;
V_14 -> V_70 = V_65 ;
V_65 = V_14 ;
V_89:
F_5 ( & V_15 , V_2 ) ;
return V_14 ;
}
static void
F_33 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
struct V_37 * V_38 ;
struct V_39 * V_41 , * V_42 , * V_40 ;
struct V_97 * V_98 ;
for ( V_98 = V_34 -> V_99 ; V_98 < & V_34 -> V_99 [ V_100 ] ; ++ V_98 ) {
if ( ! V_98 -> V_101 )
break;
F_58 ( V_98 -> V_101 ) ;
}
V_40 = & V_34 -> V_102 ;
F_20 (pos, nx, head) {
F_22 ( V_41 ) ;
V_38 = F_21 ( V_41 , struct V_37 , V_40 ) ;
F_42 ( V_38 -> V_72 ) ;
F_36 ( V_38 ) ;
}
F_36 ( V_34 ) ;
}
void
F_59 ( void )
{
struct V_13 * V_14 ;
T_1 V_2 ;
F_60 () ;
while ( ( V_14 = V_65 ) ) {
V_65 = V_14 -> V_70 ;
F_2 ( & V_14 -> V_66 , V_2 ) ;
F_19 ( V_14 ) ;
V_14 -> V_2 |= V_18 ;
F_5 ( & V_14 -> V_66 , V_2 ) ;
F_41 ( & V_14 -> V_19 ) ;
F_27 ( V_14 ) ;
}
}
int T_4
F_61 ( void )
{
return 0 ;
}
