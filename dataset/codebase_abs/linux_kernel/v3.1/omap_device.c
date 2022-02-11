static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 V_5 , V_6 , V_7 ;
F_2 ( L_1 , V_2 -> V_8 . V_9 ) ;
while ( V_2 -> V_10 > 0 ) {
struct V_11 * V_12 ;
unsigned long long V_13 = 0 ;
V_2 -> V_10 -- ;
V_12 = V_2 -> V_14 + V_2 -> V_10 ;
if ( ! V_3 &&
( V_2 -> V_15 <= V_2 -> V_16 ) )
break;
F_3 ( & V_5 ) ;
V_12 -> V_17 ( V_2 ) ;
F_3 ( & V_6 ) ;
V_7 = F_4 ( V_6 , V_5 ) ;
V_13 = F_5 ( & V_7 ) ;
F_2 ( L_2
L_3 , V_2 -> V_8 . V_9 , V_2 -> V_10 ,
V_13 ) ;
if ( V_13 > V_12 -> V_18 ) {
V_12 -> V_19 = V_13 ;
if ( V_12 -> V_20 & V_21 ) {
V_12 -> V_18 = V_13 ;
F_6 ( L_4
L_5 ,
V_2 -> V_8 . V_9 , V_2 -> V_8 . V_22 ,
V_2 -> V_10 , V_13 ) ;
} else
F_6 ( L_6
L_7
L_8 ,
V_2 -> V_8 . V_9 , V_2 -> V_8 . V_22 ,
V_2 -> V_10 , V_13 ,
V_12 -> V_18 ) ;
}
V_2 -> V_15 -= V_12 -> V_18 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 V_5 , V_6 , V_7 ;
F_2 ( L_9 , V_2 -> V_8 . V_9 ) ;
while ( V_2 -> V_10 < V_2 -> V_23 ) {
struct V_11 * V_12 ;
unsigned long long V_24 = 0 ;
V_12 = V_2 -> V_14 + V_2 -> V_10 ;
if ( ! V_3 &&
( ( V_2 -> V_15 + V_12 -> V_18 ) >
V_2 -> V_16 ) )
break;
F_3 ( & V_5 ) ;
V_12 -> V_25 ( V_2 ) ;
F_3 ( & V_6 ) ;
V_7 = F_4 ( V_6 , V_5 ) ;
V_24 = F_5 ( & V_7 ) ;
F_2 ( L_10
L_3 , V_2 -> V_8 . V_9 , V_2 -> V_10 ,
V_24 ) ;
if ( V_24 > V_12 -> V_26 ) {
V_12 -> V_27 = V_24 ;
if ( V_12 -> V_20 & V_21 ) {
V_12 -> V_26 = V_24 ;
F_6 ( L_4
L_11 ,
V_2 -> V_8 . V_9 , V_2 -> V_8 . V_22 ,
V_2 -> V_10 , V_24 ) ;
} else
F_6 ( L_12
L_7
L_8 ,
V_2 -> V_8 . V_9 , V_2 -> V_8 . V_22 ,
V_2 -> V_10 , V_24 ,
V_12 -> V_26 ) ;
}
V_2 -> V_15 += V_12 -> V_18 ;
V_2 -> V_10 ++ ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , const char * V_28 ,
const char * V_29 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
if ( ! V_28 || ! V_29 )
return;
F_2 ( L_13 ,
F_9 ( & V_2 -> V_8 . V_34 ) , V_28 , V_29 ) ;
V_31 = F_10 ( F_9 ( & V_2 -> V_8 . V_34 ) , V_28 ) ;
if ( ! F_11 ( V_31 ) ) {
F_6 ( L_14 ,
F_9 ( & V_2 -> V_8 . V_34 ) , V_28 ) ;
F_12 ( V_31 ) ;
return;
}
V_31 = F_13 ( V_29 ) ;
if ( F_11 ( V_31 ) ) {
F_14 ( L_15 ,
F_9 ( & V_2 -> V_8 . V_34 ) , V_29 ) ;
return;
}
V_33 = F_15 ( V_31 , V_28 , F_9 ( & V_2 -> V_8 . V_34 ) ) ;
if ( ! V_33 ) {
F_14 ( L_16 ,
F_9 ( & V_2 -> V_8 . V_34 ) , V_28 ) ;
return;
}
F_16 ( V_33 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
int V_37 ;
F_8 ( V_2 , L_17 , V_36 -> V_38 ) ;
for ( V_37 = 0 ; V_37 < V_36 -> V_39 ; V_37 ++ )
F_8 ( V_2 , V_36 -> V_40 [ V_37 ] . V_41 , V_36 -> V_40 [ V_37 ] . V_30 ) ;
}
T_2 F_18 ( struct V_42 * V_8 )
{
struct V_1 * V_2 ;
T_2 V_43 = 0 ;
V_2 = F_19 ( V_8 ) ;
if ( V_2 -> V_44 )
V_43 = F_20 ( V_2 -> V_45 [ 0 ] ) ;
return V_43 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_7 = 0 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_44 ; V_37 ++ )
V_7 += F_22 ( V_2 -> V_45 [ V_37 ] ) ;
F_2 ( L_18
L_19 , V_2 -> V_8 . V_9 , V_7 , V_2 -> V_44 ) ;
return V_7 ;
}
int F_23 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
int V_7 = 0 ;
int V_37 , V_31 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_44 ; V_37 ++ ) {
V_31 = F_24 ( V_2 -> V_45 [ V_37 ] , V_47 ) ;
V_47 += V_31 ;
V_7 += V_31 ;
}
return 0 ;
}
struct V_1 * F_25 ( const char * V_48 , int V_49 ,
struct V_35 * V_36 , void * V_50 ,
int V_51 ,
struct V_11 * V_14 ,
int V_23 , int V_52 )
{
struct V_35 * V_53 [] = { V_36 } ;
if ( ! V_36 )
return F_26 ( - V_54 ) ;
return F_27 ( V_48 , V_49 , V_53 , 1 , V_50 ,
V_51 , V_14 , V_23 ,
V_52 ) ;
}
struct V_1 * F_27 ( const char * V_48 , int V_49 ,
struct V_35 * * V_53 , int V_55 ,
void * V_50 , int V_51 ,
struct V_11 * V_14 ,
int V_23 , int V_52 )
{
int V_43 = - V_56 ;
struct V_1 * V_2 ;
char * V_57 ;
struct V_46 * V_47 = NULL ;
int V_37 , V_58 ;
struct V_35 * * V_45 ;
if ( ! V_53 || V_55 == 0 || ! V_48 )
return F_26 ( - V_54 ) ;
if ( ! V_50 && V_51 > 0 )
return F_26 ( - V_54 ) ;
F_2 ( L_20 , V_48 ,
V_55 ) ;
V_2 = F_28 ( sizeof( struct V_1 ) , V_59 ) ;
if ( ! V_2 )
return F_26 ( - V_56 ) ;
V_2 -> V_44 = V_55 ;
V_45 = F_28 ( sizeof( struct V_35 * ) * V_55 ,
V_59 ) ;
if ( ! V_45 )
goto V_60;
memcpy ( V_45 , V_53 , sizeof( struct V_35 * ) * V_55 ) ;
V_2 -> V_45 = V_45 ;
V_57 = F_28 ( strlen ( V_48 ) + 1 , V_59 ) ;
if ( ! V_57 )
goto V_61;
strcpy ( V_57 , V_48 ) ;
V_2 -> V_8 . V_9 = V_57 ;
V_2 -> V_8 . V_22 = V_49 ;
V_58 = F_21 ( V_2 ) ;
if ( V_58 > 0 ) {
V_47 = F_28 ( sizeof( struct V_46 ) * V_58 , V_59 ) ;
if ( ! V_47 )
goto V_62;
}
F_23 ( V_2 , V_47 ) ;
V_2 -> V_8 . V_63 = V_58 ;
V_2 -> V_8 . V_46 = V_47 ;
V_43 = F_29 ( & V_2 -> V_8 , V_50 , V_51 ) ;
if ( V_43 )
goto V_64;
V_2 -> V_14 = V_14 ;
V_2 -> V_23 = V_23 ;
if ( V_52 )
V_43 = F_30 ( V_2 ) ;
else
V_43 = F_31 ( V_2 ) ;
for ( V_37 = 0 ; V_37 < V_55 ; V_37 ++ ) {
V_45 [ V_37 ] -> V_2 = V_2 ;
F_17 ( V_2 , V_45 [ V_37 ] ) ;
}
if ( V_43 )
goto V_64;
return V_2 ;
V_64:
F_32 ( V_47 ) ;
V_62:
F_32 ( V_57 ) ;
V_61:
F_32 ( V_45 ) ;
V_60:
F_32 ( V_2 ) ;
F_14 ( L_21 , V_48 , V_43 ) ;
return F_26 ( V_43 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_42 * V_65 [ 1 ] ;
V_65 [ 0 ] = & ( V_2 -> V_8 ) ;
F_33 ( V_65 , 1 ) ;
return 0 ;
}
static int F_34 ( struct V_66 * V_34 )
{
struct V_42 * V_8 = F_35 ( V_34 ) ;
int V_43 ;
V_43 = F_36 ( V_34 ) ;
if ( ! V_43 )
F_37 ( V_8 ) ;
return V_43 ;
}
static int F_38 ( struct V_66 * V_34 )
{
return F_39 ( V_34 ) ;
}
static int F_40 ( struct V_66 * V_34 )
{
struct V_42 * V_8 = F_35 ( V_34 ) ;
F_41 ( V_8 ) ;
return F_42 ( V_34 ) ;
}
static int F_43 ( struct V_66 * V_34 )
{
struct V_42 * V_8 = F_35 ( V_34 ) ;
struct V_1 * V_2 = F_19 ( V_8 ) ;
int V_43 ;
if ( V_2 -> V_20 & V_67 )
return F_44 ( V_34 ) ;
V_43 = F_44 ( V_34 ) ;
if ( ! V_43 && ! F_45 ( V_34 ) ) {
if ( F_36 ( V_34 ) == 0 ) {
F_37 ( V_8 ) ;
V_2 -> V_20 |= V_68 ;
}
}
return V_43 ;
}
static int F_46 ( struct V_66 * V_34 )
{
struct V_42 * V_8 = F_35 ( V_34 ) ;
struct V_1 * V_2 = F_19 ( V_8 ) ;
if ( V_2 -> V_20 & V_67 )
return F_47 ( V_34 ) ;
if ( ( V_2 -> V_20 & V_68 ) &&
! F_45 ( V_34 ) ) {
V_2 -> V_20 &= ~ V_68 ;
F_41 ( V_8 ) ;
F_42 ( V_34 ) ;
}
return F_47 ( V_34 ) ;
}
int F_31 ( struct V_1 * V_2 )
{
F_2 ( L_22 , V_2 -> V_8 . V_9 ) ;
V_2 -> V_8 . V_34 . V_69 = & V_70 ;
V_2 -> V_8 . V_34 . V_71 = & V_72 ;
return F_48 ( & V_2 -> V_8 ) ;
}
int F_41 ( struct V_42 * V_8 )
{
int V_43 ;
struct V_1 * V_2 ;
V_2 = F_19 ( V_8 ) ;
if ( V_2 -> V_73 == V_74 ) {
F_49 ( 1 , L_23 ,
V_2 -> V_8 . V_9 , V_2 -> V_8 . V_22 , V_75 , V_2 -> V_73 ) ;
return - V_54 ;
}
if ( V_2 -> V_73 == V_76 )
V_2 -> V_10 = V_2 -> V_23 ;
V_43 = F_1 ( V_2 , V_77 ) ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = V_78 ;
V_2 -> V_73 = V_74 ;
return V_43 ;
}
int F_37 ( struct V_42 * V_8 )
{
int V_43 ;
struct V_1 * V_2 ;
V_2 = F_19 ( V_8 ) ;
if ( V_2 -> V_73 != V_74 ) {
F_49 ( 1 , L_23 ,
V_2 -> V_8 . V_9 , V_2 -> V_8 . V_22 , V_75 , V_2 -> V_73 ) ;
return - V_54 ;
}
V_43 = F_7 ( V_2 , V_79 ) ;
V_2 -> V_73 = V_80 ;
return V_43 ;
}
int F_50 ( struct V_42 * V_8 )
{
int V_43 , V_37 ;
struct V_1 * V_2 ;
V_2 = F_19 ( V_8 ) ;
if ( V_2 -> V_73 != V_74 &&
V_2 -> V_73 != V_80 ) {
F_49 ( 1 , L_23 ,
V_2 -> V_8 . V_9 , V_2 -> V_8 . V_22 , V_75 , V_2 -> V_73 ) ;
return - V_54 ;
}
V_43 = F_7 ( V_2 , V_77 ) ;
for ( V_37 = 0 ; V_37 < V_2 -> V_44 ; V_37 ++ )
F_51 ( V_2 -> V_45 [ V_37 ] ) ;
V_2 -> V_73 = V_81 ;
return V_43 ;
}
int F_52 ( struct V_42 * V_8 ,
T_2 V_82 )
{
int V_43 = - V_54 ;
struct V_1 * V_2 ;
V_2 = F_19 ( V_8 ) ;
if ( V_82 == V_2 -> V_15 )
return 0 ;
V_2 -> V_16 = V_82 ;
if ( V_2 -> V_73 != V_80 )
return 0 ;
else if ( V_82 > V_2 -> V_15 )
V_43 = F_7 ( V_2 , V_79 ) ;
else if ( V_82 < V_2 -> V_15 )
V_43 = F_1 ( V_2 , V_79 ) ;
return V_43 ;
}
struct V_83 * F_53 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_44 )
return NULL ;
return F_54 ( V_2 -> V_45 [ 0 ] ) ;
}
void T_3 * F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_44 != 1 )
return NULL ;
return F_56 ( V_2 -> V_45 [ 0 ] ) ;
}
int F_57 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_44 ; V_37 ++ )
F_58 ( V_2 -> V_45 [ V_37 ] ) ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_44 ; V_37 ++ )
F_60 ( V_2 -> V_45 [ V_37 ] ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_44 ; V_37 ++ )
F_62 ( V_2 -> V_45 [ V_37 ] ) ;
return 0 ;
}
int F_63 ( struct V_1 * V_2 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_44 ; V_37 ++ )
F_64 ( V_2 -> V_45 [ V_37 ] ) ;
return 0 ;
}
static int T_4 F_65 ( void )
{
return F_66 ( & V_70 ) ;
}
