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
static inline struct V_1 * F_8 ( struct V_28 * V_8 )
{
return F_9 ( V_8 , struct V_1 , V_8 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_30 -> V_32 ; V_31 ++ ) {
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
V_34 = & V_30 -> V_39 [ V_31 ] ;
if ( ! V_34 -> V_40 )
continue;
V_36 = F_11 ( F_12 ( & V_2 -> V_8 . V_41 ) , V_34 -> V_42 ) ;
if ( ! F_13 ( V_36 ) )
continue;
V_36 = F_14 ( ( char * ) V_34 -> V_35 ) ;
if ( F_13 ( V_36 ) ) {
F_15 ( L_13 ,
F_12 ( & V_2 -> V_8 . V_41 ) , V_34 -> V_35 ) ;
continue;
}
V_38 = F_16 ( V_36 , V_34 -> V_42 , F_12 ( & V_2 -> V_8 . V_41 ) ) ;
if ( ! V_38 ) {
F_15 ( L_14 ,
F_12 ( & V_2 -> V_8 . V_41 ) , V_34 -> V_42 ) ;
return;
}
F_17 ( V_38 ) ;
}
}
T_2 F_18 ( struct V_28 * V_8 )
{
struct V_1 * V_2 ;
T_2 V_43 = 0 ;
V_2 = F_8 ( V_8 ) ;
if ( V_2 -> V_44 )
V_43 = F_19 ( V_2 -> V_45 [ 0 ] ) ;
return V_43 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_7 = 0 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_44 ; V_31 ++ )
V_7 += F_21 ( V_2 -> V_45 [ V_31 ] ) ;
F_2 ( L_15
L_16 , V_2 -> V_8 . V_9 , V_7 , V_2 -> V_44 ) ;
return V_7 ;
}
int F_22 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
int V_7 = 0 ;
int V_31 , V_36 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_44 ; V_31 ++ ) {
V_36 = F_23 ( V_2 -> V_45 [ V_31 ] , V_47 ) ;
V_47 += V_36 ;
V_7 += V_36 ;
}
return 0 ;
}
struct V_1 * F_24 ( const char * V_48 , int V_49 ,
struct V_29 * V_30 , void * V_50 ,
int V_51 ,
struct V_11 * V_14 ,
int V_23 , int V_52 )
{
struct V_29 * V_53 [] = { V_30 } ;
if ( ! V_30 )
return F_25 ( - V_54 ) ;
return F_26 ( V_48 , V_49 , V_53 , 1 , V_50 ,
V_51 , V_14 , V_23 ,
V_52 ) ;
}
struct V_1 * F_26 ( const char * V_48 , int V_49 ,
struct V_29 * * V_53 , int V_55 ,
void * V_50 , int V_51 ,
struct V_11 * V_14 ,
int V_23 , int V_52 )
{
int V_43 = - V_56 ;
struct V_1 * V_2 ;
char * V_57 ;
struct V_46 * V_47 = NULL ;
int V_31 , V_58 ;
struct V_29 * * V_45 ;
if ( ! V_53 || V_55 == 0 || ! V_48 )
return F_25 ( - V_54 ) ;
if ( ! V_50 && V_51 > 0 )
return F_25 ( - V_54 ) ;
F_2 ( L_17 , V_48 ,
V_55 ) ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_59 ) ;
if ( ! V_2 )
return F_25 ( - V_56 ) ;
V_2 -> V_44 = V_55 ;
V_45 = F_27 ( sizeof( struct V_29 * ) * V_55 ,
V_59 ) ;
if ( ! V_45 )
goto V_60;
memcpy ( V_45 , V_53 , sizeof( struct V_29 * ) * V_55 ) ;
V_2 -> V_45 = V_45 ;
V_57 = F_27 ( strlen ( V_48 ) + 1 , V_59 ) ;
if ( ! V_57 )
goto V_61;
strcpy ( V_57 , V_48 ) ;
V_2 -> V_8 . V_9 = V_57 ;
V_2 -> V_8 . V_22 = V_49 ;
V_58 = F_20 ( V_2 ) ;
if ( V_58 > 0 ) {
V_47 = F_27 ( sizeof( struct V_46 ) * V_58 , V_59 ) ;
if ( ! V_47 )
goto V_62;
}
F_22 ( V_2 , V_47 ) ;
V_2 -> V_8 . V_63 = V_58 ;
V_2 -> V_8 . V_46 = V_47 ;
V_43 = F_28 ( & V_2 -> V_8 , V_50 , V_51 ) ;
if ( V_43 )
goto V_64;
V_2 -> V_14 = V_14 ;
V_2 -> V_23 = V_23 ;
if ( V_52 )
V_43 = F_29 ( V_2 ) ;
else
V_43 = F_30 ( V_2 ) ;
for ( V_31 = 0 ; V_31 < V_55 ; V_31 ++ ) {
V_45 [ V_31 ] -> V_2 = V_2 ;
F_10 ( V_2 , V_45 [ V_31 ] ) ;
}
if ( V_43 )
goto V_64;
return V_2 ;
V_64:
F_31 ( V_47 ) ;
V_62:
F_31 ( V_57 ) ;
V_61:
F_31 ( V_45 ) ;
V_60:
F_31 ( V_2 ) ;
F_15 ( L_18 , V_48 , V_43 ) ;
return F_25 ( V_43 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_28 * V_65 [ 1 ] ;
V_65 [ 0 ] = & ( V_2 -> V_8 ) ;
F_32 ( V_65 , 1 ) ;
return 0 ;
}
static int F_33 ( struct V_66 * V_41 )
{
struct V_28 * V_8 = F_34 ( V_41 ) ;
int V_43 ;
V_43 = F_35 ( V_41 ) ;
if ( ! V_43 )
F_36 ( V_8 ) ;
return V_43 ;
}
static int F_37 ( struct V_66 * V_41 )
{
return F_38 ( V_41 ) ;
}
static int F_39 ( struct V_66 * V_41 )
{
struct V_28 * V_8 = F_34 ( V_41 ) ;
F_40 ( V_8 ) ;
return F_41 ( V_41 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
F_2 ( L_19 , V_2 -> V_8 . V_9 ) ;
V_2 -> V_8 . V_41 . V_67 = & V_68 ;
V_2 -> V_8 . V_41 . V_69 = & V_70 ;
return F_42 ( & V_2 -> V_8 ) ;
}
int F_40 ( struct V_28 * V_8 )
{
int V_43 ;
struct V_1 * V_2 ;
V_2 = F_8 ( V_8 ) ;
if ( V_2 -> V_71 == V_72 ) {
F_43 ( 1 , L_20 ,
V_2 -> V_8 . V_9 , V_2 -> V_8 . V_22 , V_73 , V_2 -> V_71 ) ;
return - V_54 ;
}
if ( V_2 -> V_71 == V_74 )
V_2 -> V_10 = V_2 -> V_23 ;
V_43 = F_1 ( V_2 , V_75 ) ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = V_76 ;
V_2 -> V_71 = V_72 ;
return V_43 ;
}
int F_36 ( struct V_28 * V_8 )
{
int V_43 ;
struct V_1 * V_2 ;
V_2 = F_8 ( V_8 ) ;
if ( V_2 -> V_71 != V_72 ) {
F_43 ( 1 , L_20 ,
V_2 -> V_8 . V_9 , V_2 -> V_8 . V_22 , V_73 , V_2 -> V_71 ) ;
return - V_54 ;
}
V_43 = F_7 ( V_2 , V_77 ) ;
V_2 -> V_71 = V_78 ;
return V_43 ;
}
int F_44 ( struct V_28 * V_8 )
{
int V_43 , V_31 ;
struct V_1 * V_2 ;
V_2 = F_8 ( V_8 ) ;
if ( V_2 -> V_71 != V_72 &&
V_2 -> V_71 != V_78 ) {
F_43 ( 1 , L_20 ,
V_2 -> V_8 . V_9 , V_2 -> V_8 . V_22 , V_73 , V_2 -> V_71 ) ;
return - V_54 ;
}
V_43 = F_7 ( V_2 , V_75 ) ;
for ( V_31 = 0 ; V_31 < V_2 -> V_44 ; V_31 ++ )
F_45 ( V_2 -> V_45 [ V_31 ] ) ;
V_2 -> V_71 = V_79 ;
return V_43 ;
}
int F_46 ( struct V_28 * V_8 ,
T_2 V_80 )
{
int V_43 = - V_54 ;
struct V_1 * V_2 ;
V_2 = F_8 ( V_8 ) ;
if ( V_80 == V_2 -> V_15 )
return 0 ;
V_2 -> V_16 = V_80 ;
if ( V_2 -> V_71 != V_78 )
return 0 ;
else if ( V_80 > V_2 -> V_15 )
V_43 = F_7 ( V_2 , V_77 ) ;
else if ( V_80 < V_2 -> V_15 )
V_43 = F_1 ( V_2 , V_77 ) ;
return V_43 ;
}
struct V_81 * F_47 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_44 )
return NULL ;
return F_48 ( V_2 -> V_45 [ 0 ] ) ;
}
void T_3 * F_49 ( struct V_1 * V_2 )
{
if ( V_2 -> V_44 != 1 )
return NULL ;
return F_50 ( V_2 -> V_45 [ 0 ] ) ;
}
int F_51 ( struct V_1 * V_2 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_44 ; V_31 ++ )
F_52 ( V_2 -> V_45 [ V_31 ] ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_44 ; V_31 ++ )
F_54 ( V_2 -> V_45 [ V_31 ] ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_44 ; V_31 ++ )
F_56 ( V_2 -> V_45 [ V_31 ] ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_44 ; V_31 ++ )
F_58 ( V_2 -> V_45 [ V_31 ] ) ;
return 0 ;
}
static int T_4 F_59 ( void )
{
return F_60 ( & V_68 ) ;
}
