void T_1 F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
}
struct V_4 * F_2 ( struct V_5 * V_5 )
{
unsigned long V_6 = F_3 ( V_5 ) ;
unsigned long V_7 ;
struct V_4 * V_8 ;
V_8 = F_4 ( F_5 ( V_5 ) ) -> V_3 ;
#ifdef F_6
if ( F_7 ( ! V_8 ) )
return NULL ;
#endif
V_7 = V_6 - F_4 ( F_5 ( V_5 ) ) -> V_9 ;
return V_8 + V_7 ;
}
static int T_2 F_8 ( int V_10 )
{
struct V_4 * V_8 ;
unsigned long V_11 ;
unsigned long V_12 ;
V_12 = F_4 ( V_10 ) -> V_13 ;
if ( ! V_12 )
return 0 ;
V_11 = sizeof( struct V_4 ) * V_12 ;
V_8 = F_9 (
V_11 , V_14 , F_10 ( V_15 ) ,
V_16 , V_10 ) ;
if ( ! V_8 )
return - V_17 ;
F_4 ( V_10 ) -> V_3 = V_8 ;
V_18 += V_11 ;
return 0 ;
}
void T_2 F_11 ( void )
{
int V_10 , V_19 ;
if ( F_12 () )
return;
F_13 (nid) {
V_19 = F_8 ( V_10 ) ;
if ( V_19 )
goto V_19;
}
F_14 ( V_20 L_1 , V_18 ) ;
F_14 ( V_20 L_2
L_3 ) ;
return;
V_19:
F_14 ( V_21 L_4 ) ;
F_14 ( V_21 L_5 ) ;
F_15 ( L_6 ) ;
}
struct V_4 * F_2 ( struct V_5 * V_5 )
{
unsigned long V_6 = F_3 ( V_5 ) ;
struct V_22 * V_23 = F_16 ( V_6 ) ;
#ifdef F_6
if ( ! V_23 -> V_4 )
return NULL ;
#endif
return V_23 -> V_4 + V_6 ;
}
static void * T_1 F_17 ( T_3 V_24 , int V_10 )
{
T_4 V_25 = V_26 | V_27 | V_28 ;
void * V_29 = NULL ;
V_29 = F_18 ( V_10 , V_24 , V_25 ) ;
if ( V_29 ) {
F_19 ( V_29 , V_24 , 1 , V_25 ) ;
return V_29 ;
}
if ( F_20 ( V_10 , V_30 ) )
V_29 = F_21 ( V_24 , V_10 ) ;
else
V_29 = F_22 ( V_24 ) ;
return V_29 ;
}
static int T_1 F_23 ( unsigned long V_6 , int V_10 )
{
struct V_22 * V_23 ;
struct V_4 * V_8 ;
unsigned long V_11 ;
V_23 = F_16 ( V_6 ) ;
if ( V_23 -> V_4 )
return 0 ;
V_11 = sizeof( struct V_4 ) * V_31 ;
V_8 = F_17 ( V_11 , V_10 ) ;
F_24 ( V_8 ) ;
if ( ! V_8 ) {
F_14 ( V_32 L_7 ) ;
return - V_17 ;
}
V_6 &= V_33 ;
V_23 -> V_4 = V_8 - V_6 ;
V_18 += V_11 ;
return 0 ;
}
static void F_25 ( void * V_29 )
{
if ( F_26 ( V_29 ) ) {
F_27 ( V_29 ) ;
} else {
struct V_5 * V_5 = F_28 ( V_29 ) ;
T_3 V_11 =
sizeof( struct V_4 ) * V_31 ;
F_29 ( F_30 ( V_5 ) ) ;
F_31 ( V_29 ) ;
F_32 ( V_29 , V_11 ) ;
}
}
static void F_33 ( unsigned long V_6 )
{
struct V_22 * V_34 ;
struct V_4 * V_8 ;
V_34 = F_16 ( V_6 ) ;
if ( ! V_34 || ! V_34 -> V_4 )
return;
V_8 = V_34 -> V_4 + V_6 ;
F_25 ( V_8 ) ;
V_34 -> V_4 = NULL ;
}
static int T_1 F_34 ( unsigned long V_35 ,
unsigned long V_12 ,
int V_10 )
{
unsigned long V_36 , V_37 , V_6 ;
int V_19 = 0 ;
V_36 = F_35 ( V_35 ) ;
V_37 = F_36 ( V_35 + V_12 ) ;
if ( V_10 == - 1 ) {
V_10 = F_37 ( V_35 ) ;
F_38 ( ! F_20 ( V_10 , V_38 ) ) ;
}
for ( V_6 = V_36 ; ! V_19 && V_6 < V_37 ; V_6 += V_31 ) {
if ( ! F_39 ( V_6 ) )
continue;
V_19 = F_23 ( V_6 , V_10 ) ;
}
if ( ! V_19 )
return 0 ;
for ( V_6 = V_36 ; V_6 < V_37 ; V_6 += V_31 )
F_33 ( V_6 ) ;
return - V_17 ;
}
static int T_1 F_40 ( unsigned long V_35 ,
unsigned long V_12 , int V_10 )
{
unsigned long V_36 , V_37 , V_6 ;
V_36 = F_35 ( V_35 ) ;
V_37 = F_36 ( V_35 + V_12 ) ;
for ( V_6 = V_36 ; V_6 < V_37 ; V_6 += V_31 )
F_33 ( V_6 ) ;
return 0 ;
}
static int T_1 F_41 ( struct V_39 * V_40 ,
unsigned long V_41 , void * V_42 )
{
struct V_43 * V_44 = V_42 ;
int V_45 = 0 ;
switch ( V_41 ) {
case V_46 :
V_45 = F_34 ( V_44 -> V_35 ,
V_44 -> V_12 , V_44 -> V_47 ) ;
break;
case V_48 :
F_40 ( V_44 -> V_35 ,
V_44 -> V_12 , V_44 -> V_47 ) ;
break;
case V_49 :
F_40 ( V_44 -> V_35 ,
V_44 -> V_12 , V_44 -> V_47 ) ;
break;
case V_50 :
break;
case V_51 :
case V_52 :
break;
}
return F_42 ( V_45 ) ;
}
void T_2 F_43 ( void )
{
unsigned long V_6 ;
int V_10 ;
if ( F_12 () )
return;
F_44 (nid, N_MEMORY) {
unsigned long V_35 , V_53 ;
V_35 = V_9 ( V_10 ) ;
V_53 = F_45 ( V_10 ) ;
for ( V_6 = V_35 ;
V_6 < V_53 ;
V_6 = F_46 ( V_6 + 1 , V_31 ) ) {
if ( ! F_47 ( V_6 ) )
continue;
if ( F_37 ( V_6 ) != V_10 )
continue;
if ( F_23 ( V_6 , V_10 ) )
goto V_54;
}
}
F_48 ( F_41 , 0 ) ;
F_14 ( V_20 L_1 , V_18 ) ;
F_14 ( V_20 L_8
L_9 ) ;
return;
V_54:
F_14 ( V_21 L_10 ) ;
F_15 ( L_6 ) ;
}
void T_1 F_1 ( struct V_1 * V_2 )
{
return;
}
static int F_49 ( int type )
{
struct V_5 * V_5 ;
struct V_55 * V_56 ;
unsigned long V_57 , V_58 ;
V_56 = & V_55 [ type ] ;
for ( V_57 = 0 ; V_57 < V_56 -> V_59 ; V_57 ++ ) {
V_5 = F_50 ( V_26 | V_27 ) ;
if ( ! V_5 )
goto V_60;
V_56 -> V_61 [ V_57 ] = V_5 ;
}
return 0 ;
V_60:
V_58 = V_57 ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ )
F_51 ( V_56 -> V_61 [ V_57 ] ) ;
return - V_17 ;
}
static struct V_62 * F_52 ( T_5 V_63 ,
struct V_55 * * V_64 )
{
T_6 V_7 = F_53 ( V_63 ) ;
struct V_55 * V_56 ;
struct V_5 * V_65 ;
struct V_62 * V_66 ;
V_56 = & V_55 [ F_54 ( V_63 ) ] ;
if ( V_64 )
* V_64 = V_56 ;
V_65 = V_56 -> V_61 [ V_7 / V_67 ] ;
V_66 = F_55 ( V_65 ) ;
return V_66 + V_7 % V_67 ;
}
unsigned short F_56 ( T_5 V_63 ,
unsigned short V_68 , unsigned short V_69 )
{
struct V_55 * V_56 ;
struct V_62 * V_66 ;
unsigned long V_25 ;
unsigned short V_70 ;
V_66 = F_52 ( V_63 , & V_56 ) ;
F_57 ( & V_56 -> V_71 , V_25 ) ;
V_70 = V_66 -> V_72 ;
if ( V_70 == V_68 )
V_66 -> V_72 = V_69 ;
else
V_70 = 0 ;
F_58 ( & V_56 -> V_71 , V_25 ) ;
return V_70 ;
}
unsigned short F_59 ( T_5 V_63 , unsigned short V_72 )
{
struct V_55 * V_56 ;
struct V_62 * V_66 ;
unsigned short V_68 ;
unsigned long V_25 ;
V_66 = F_52 ( V_63 , & V_56 ) ;
F_57 ( & V_56 -> V_71 , V_25 ) ;
V_68 = V_66 -> V_72 ;
V_66 -> V_72 = V_72 ;
F_58 ( & V_56 -> V_71 , V_25 ) ;
return V_68 ;
}
unsigned short F_60 ( T_5 V_63 )
{
return F_52 ( V_63 , NULL ) -> V_72 ;
}
int F_61 ( int type , unsigned long V_73 )
{
void * V_74 ;
unsigned long V_75 ;
unsigned long V_59 ;
struct V_55 * V_56 ;
if ( ! V_76 )
return 0 ;
V_59 = F_62 ( V_73 , V_67 ) ;
V_75 = V_59 * sizeof( void * ) ;
V_74 = F_22 ( V_75 ) ;
if ( ! V_74 )
goto V_77;
V_56 = & V_55 [ type ] ;
F_63 ( & V_78 ) ;
V_56 -> V_59 = V_59 ;
V_56 -> V_61 = V_74 ;
F_64 ( & V_56 -> V_71 ) ;
if ( F_49 ( type ) ) {
V_56 -> V_61 = NULL ;
V_56 -> V_59 = 0 ;
F_65 ( & V_78 ) ;
F_27 ( V_74 ) ;
goto V_77;
}
F_65 ( & V_78 ) ;
return 0 ;
V_77:
F_14 ( V_20 L_11 ) ;
F_14 ( V_20
L_12 ) ;
return - V_17 ;
}
void F_66 ( int type )
{
struct V_5 * * V_61 ;
unsigned long V_79 , V_59 ;
struct V_55 * V_56 ;
if ( ! V_76 )
return;
F_63 ( & V_78 ) ;
V_56 = & V_55 [ type ] ;
V_61 = V_56 -> V_61 ;
V_59 = V_56 -> V_59 ;
V_56 -> V_61 = NULL ;
V_56 -> V_59 = 0 ;
F_65 ( & V_78 ) ;
if ( V_61 ) {
for ( V_79 = 0 ; V_79 < V_59 ; V_79 ++ ) {
struct V_5 * V_5 = V_61 [ V_79 ] ;
if ( V_5 )
F_51 ( V_5 ) ;
}
F_27 ( V_61 ) ;
}
}
