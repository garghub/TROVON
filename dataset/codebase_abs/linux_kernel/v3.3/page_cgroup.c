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
V_8 = F_9 ( F_4 ( V_10 ) ,
V_11 , V_14 , F_10 ( V_15 ) ) ;
if ( ! V_8 )
return - V_16 ;
F_4 ( V_10 ) -> V_3 = V_8 ;
V_17 += V_11 ;
return 0 ;
}
void T_2 F_11 ( void )
{
int V_10 , V_18 ;
if ( F_12 () )
return;
F_13 (nid) {
V_18 = F_8 ( V_10 ) ;
if ( V_18 )
goto V_18;
}
F_14 ( V_19 L_1 , V_17 ) ;
F_14 ( V_19 L_2
L_3 ) ;
return;
V_18:
F_14 ( V_20 L_4 ) ;
F_14 ( V_20 L_5 ) ;
F_15 ( L_6 ) ;
}
struct V_4 * F_2 ( struct V_5 * V_5 )
{
unsigned long V_6 = F_3 ( V_5 ) ;
struct V_21 * V_22 = F_16 ( V_6 ) ;
#ifdef F_6
if ( ! V_22 -> V_4 )
return NULL ;
#endif
return V_22 -> V_4 + V_6 ;
}
static void * T_1 F_17 ( T_3 V_23 , int V_10 )
{
T_4 V_24 = V_25 | V_26 | V_27 ;
void * V_28 = NULL ;
V_28 = F_18 ( V_10 , V_23 , V_24 ) ;
if ( V_28 ) {
F_19 ( V_28 , V_23 , 1 , V_24 ) ;
return V_28 ;
}
if ( F_20 ( V_10 , V_29 ) )
V_28 = F_21 ( V_23 , V_10 ) ;
else
V_28 = F_22 ( V_23 ) ;
return V_28 ;
}
static int T_1 F_23 ( unsigned long V_6 , int V_10 )
{
struct V_21 * V_22 ;
struct V_4 * V_8 ;
unsigned long V_11 ;
V_22 = F_16 ( V_6 ) ;
if ( V_22 -> V_4 )
return 0 ;
V_11 = sizeof( struct V_4 ) * V_30 ;
V_8 = F_17 ( V_11 , V_10 ) ;
F_24 ( V_8 ) ;
if ( ! V_8 ) {
F_14 ( V_31 L_7 ) ;
return - V_16 ;
}
V_6 &= V_32 ;
V_22 -> V_4 = V_8 - V_6 ;
V_17 += V_11 ;
return 0 ;
}
static void F_25 ( void * V_28 )
{
if ( F_26 ( V_28 ) ) {
F_27 ( V_28 ) ;
} else {
struct V_5 * V_5 = F_28 ( V_28 ) ;
T_3 V_11 =
sizeof( struct V_4 ) * V_30 ;
F_29 ( F_30 ( V_5 ) ) ;
F_31 ( V_28 , V_11 ) ;
}
}
void F_32 ( unsigned long V_6 )
{
struct V_21 * V_33 ;
struct V_4 * V_8 ;
V_33 = F_16 ( V_6 ) ;
if ( ! V_33 || ! V_33 -> V_4 )
return;
V_8 = V_33 -> V_4 + V_6 ;
F_25 ( V_8 ) ;
V_33 -> V_4 = NULL ;
}
int T_1 F_33 ( unsigned long V_34 ,
unsigned long V_12 ,
int V_10 )
{
unsigned long V_35 , V_36 , V_6 ;
int V_18 = 0 ;
V_35 = F_34 ( V_34 ) ;
V_36 = F_35 ( V_34 + V_12 ) ;
if ( V_10 == - 1 ) {
V_10 = F_36 ( V_34 ) ;
F_37 ( ! F_20 ( V_10 , V_37 ) ) ;
}
for ( V_6 = V_35 ; ! V_18 && V_6 < V_36 ; V_6 += V_30 ) {
if ( ! F_38 ( V_6 ) )
continue;
V_18 = F_23 ( V_6 , V_10 ) ;
}
if ( ! V_18 )
return 0 ;
for ( V_6 = V_35 ; V_6 < V_36 ; V_6 += V_30 )
F_32 ( V_6 ) ;
return - V_16 ;
}
int T_1 F_39 ( unsigned long V_34 ,
unsigned long V_12 , int V_10 )
{
unsigned long V_35 , V_36 , V_6 ;
V_35 = F_34 ( V_34 ) ;
V_36 = F_35 ( V_34 + V_12 ) ;
for ( V_6 = V_35 ; V_6 < V_36 ; V_6 += V_30 )
F_32 ( V_6 ) ;
return 0 ;
}
static int T_1 F_40 ( struct V_38 * V_39 ,
unsigned long V_40 , void * V_41 )
{
struct V_42 * V_43 = V_41 ;
int V_44 = 0 ;
switch ( V_40 ) {
case V_45 :
V_44 = F_33 ( V_43 -> V_34 ,
V_43 -> V_12 , V_43 -> V_46 ) ;
break;
case V_47 :
F_39 ( V_43 -> V_34 ,
V_43 -> V_12 , V_43 -> V_46 ) ;
break;
case V_48 :
case V_49 :
break;
case V_50 :
case V_51 :
break;
}
return F_41 ( V_44 ) ;
}
void T_2 F_42 ( void )
{
unsigned long V_6 ;
int V_10 ;
if ( F_12 () )
return;
F_43 (nid, N_HIGH_MEMORY) {
unsigned long V_34 , V_52 ;
V_34 = V_9 ( V_10 ) ;
V_52 = F_44 ( V_10 ) ;
for ( V_6 = V_34 ;
V_6 < V_52 ;
V_6 = F_45 ( V_6 + 1 , V_30 ) ) {
if ( ! F_46 ( V_6 ) )
continue;
if ( F_36 ( V_6 ) != V_10 )
continue;
if ( F_23 ( V_6 , V_10 ) )
goto V_53;
}
}
F_47 ( F_40 , 0 ) ;
F_14 ( V_19 L_1 , V_17 ) ;
F_14 ( V_19 L_8
L_9 ) ;
return;
V_53:
F_14 ( V_20 L_10 ) ;
F_15 ( L_6 ) ;
}
void T_1 F_1 ( struct V_1 * V_2 )
{
return;
}
static int F_48 ( int type )
{
struct V_5 * V_5 ;
struct V_54 * V_55 ;
unsigned long V_56 , V_57 ;
V_55 = & V_54 [ type ] ;
for ( V_56 = 0 ; V_56 < V_55 -> V_58 ; V_56 ++ ) {
V_5 = F_49 ( V_25 | V_26 ) ;
if ( ! V_5 )
goto V_59;
V_55 -> V_60 [ V_56 ] = V_5 ;
}
return 0 ;
V_59:
V_57 = V_56 ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ )
F_50 ( V_55 -> V_60 [ V_56 ] ) ;
return - V_16 ;
}
static struct V_61 * F_51 ( T_5 V_62 ,
struct V_54 * * V_63 )
{
T_6 V_7 = F_52 ( V_62 ) ;
struct V_54 * V_55 ;
struct V_5 * V_64 ;
struct V_61 * V_65 ;
V_55 = & V_54 [ F_53 ( V_62 ) ] ;
if ( V_63 )
* V_63 = V_55 ;
V_64 = V_55 -> V_60 [ V_7 / V_66 ] ;
V_65 = F_54 ( V_64 ) ;
return V_65 + V_7 % V_66 ;
}
unsigned short F_55 ( T_5 V_62 ,
unsigned short V_67 , unsigned short V_68 )
{
struct V_54 * V_55 ;
struct V_61 * V_65 ;
unsigned long V_24 ;
unsigned short V_69 ;
V_65 = F_51 ( V_62 , & V_55 ) ;
F_56 ( & V_55 -> V_70 , V_24 ) ;
V_69 = V_65 -> V_71 ;
if ( V_69 == V_67 )
V_65 -> V_71 = V_68 ;
else
V_69 = 0 ;
F_57 ( & V_55 -> V_70 , V_24 ) ;
return V_69 ;
}
unsigned short F_58 ( T_5 V_62 , unsigned short V_71 )
{
struct V_54 * V_55 ;
struct V_61 * V_65 ;
unsigned short V_67 ;
unsigned long V_24 ;
V_65 = F_51 ( V_62 , & V_55 ) ;
F_56 ( & V_55 -> V_70 , V_24 ) ;
V_67 = V_65 -> V_71 ;
V_65 -> V_71 = V_71 ;
F_57 ( & V_55 -> V_70 , V_24 ) ;
return V_67 ;
}
unsigned short F_59 ( T_5 V_62 )
{
return F_51 ( V_62 , NULL ) -> V_71 ;
}
int F_60 ( int type , unsigned long V_72 )
{
void * V_73 ;
unsigned long V_74 ;
unsigned long V_58 ;
struct V_54 * V_55 ;
if ( ! V_75 )
return 0 ;
V_58 = F_61 ( V_72 , V_66 ) ;
V_74 = V_58 * sizeof( void * ) ;
V_73 = F_22 ( V_74 ) ;
if ( ! V_73 )
goto V_76;
V_55 = & V_54 [ type ] ;
F_62 ( & V_77 ) ;
V_55 -> V_58 = V_58 ;
V_55 -> V_60 = V_73 ;
F_63 ( & V_55 -> V_70 ) ;
if ( F_48 ( type ) ) {
V_55 -> V_60 = NULL ;
V_55 -> V_58 = 0 ;
F_64 ( & V_77 ) ;
F_27 ( V_73 ) ;
goto V_76;
}
F_64 ( & V_77 ) ;
return 0 ;
V_76:
F_14 ( V_19 L_11 ) ;
F_14 ( V_19
L_12 ) ;
return - V_16 ;
}
void F_65 ( int type )
{
struct V_5 * * V_60 ;
unsigned long V_78 , V_58 ;
struct V_54 * V_55 ;
if ( ! V_75 )
return;
F_62 ( & V_77 ) ;
V_55 = & V_54 [ type ] ;
V_60 = V_55 -> V_60 ;
V_58 = V_55 -> V_58 ;
V_55 -> V_60 = NULL ;
V_55 -> V_58 = 0 ;
F_64 ( & V_77 ) ;
if ( V_60 ) {
for ( V_78 = 0 ; V_78 < V_58 ; V_78 ++ ) {
struct V_5 * V_5 = V_60 [ V_78 ] ;
if ( V_5 )
F_50 ( V_5 ) ;
}
F_27 ( V_60 ) ;
}
}
