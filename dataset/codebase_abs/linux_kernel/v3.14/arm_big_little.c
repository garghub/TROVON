static inline int F_1 ( int V_1 )
{
return F_2 ( V_1 ) ;
}
static inline int F_3 ( int V_1 )
{
return F_4 () ?
V_2 : F_1 ( V_1 ) ;
}
static unsigned int F_5 ( int V_3 )
{
int V_4 ;
T_1 V_5 = 0 , V_6 ;
F_6 (j) {
V_6 = F_7 ( V_7 , V_4 ) ;
if ( ( V_3 == F_7 ( V_8 , V_4 ) ) &&
( V_5 < V_6 ) )
V_5 = V_6 ;
}
F_8 ( L_1 , V_9 , V_3 ,
V_5 ) ;
return V_5 ;
}
static unsigned int F_9 ( unsigned int V_1 )
{
T_1 V_10 = F_7 ( V_8 , V_1 ) ;
T_1 V_11 = F_10 ( V_12 [ V_10 ] ) / 1000 ;
if ( F_4 () )
V_11 = F_11 ( V_10 , V_11 ) ;
F_8 ( L_2 , V_9 , V_1 ,
V_10 , V_11 ) ;
return V_11 ;
}
static unsigned int F_12 ( unsigned int V_1 )
{
if ( F_4 () ) {
F_8 ( L_3 , V_9 , F_7 ( V_7 ,
V_1 ) ) ;
return F_7 ( V_7 , V_1 ) ;
} else {
return F_9 ( V_1 ) ;
}
}
static unsigned int
F_13 ( T_1 V_1 , T_1 V_13 , T_1 V_14 , T_1 V_11 )
{
T_1 V_15 , V_16 ;
int V_17 ;
bool V_18 = F_4 () ;
F_14 ( & V_19 [ V_14 ] ) ;
if ( V_18 ) {
V_16 = F_7 ( V_7 , V_1 ) ;
F_7 ( V_7 , V_1 ) = V_11 ;
F_7 ( V_8 , V_1 ) = V_14 ;
V_15 = F_5 ( V_14 ) ;
V_15 = F_15 ( V_14 , V_15 ) ;
} else {
V_15 = V_11 ;
}
F_8 ( L_4 ,
V_9 , V_1 , V_13 , V_14 , V_15 ) ;
V_17 = F_16 ( V_12 [ V_14 ] , V_15 * 1000 ) ;
if ( F_17 ( V_17 ) ) {
F_18 ( L_5 , V_17 ,
V_14 ) ;
if ( V_18 ) {
F_7 ( V_7 , V_1 ) = V_16 ;
F_7 ( V_8 , V_1 ) = V_13 ;
}
F_19 ( & V_19 [ V_14 ] ) ;
return V_17 ;
}
F_19 ( & V_19 [ V_14 ] ) ;
if ( V_13 != V_14 ) {
F_8 ( L_6 ,
V_9 , V_1 , V_13 , V_14 ) ;
F_20 ( V_1 , V_14 ) ;
F_14 ( & V_19 [ V_13 ] ) ;
V_15 = F_5 ( V_13 ) ;
V_15 = F_15 ( V_13 , V_15 ) ;
if ( V_15 ) {
F_8 ( L_7 ,
V_9 , V_13 , V_15 ) ;
if ( F_16 ( V_12 [ V_13 ] , V_15 * 1000 ) )
F_18 ( L_8 ,
V_9 , V_17 , V_13 ) ;
}
F_19 ( & V_19 [ V_13 ] ) ;
}
return 0 ;
}
static int F_21 ( struct V_20 * V_21 ,
unsigned int V_22 )
{
T_1 V_1 = V_21 -> V_1 , V_10 , V_14 , V_23 ;
unsigned int V_24 ;
V_10 = F_3 ( V_1 ) ;
V_14 = V_23 = F_7 ( V_8 , V_1 ) ;
V_24 = V_25 [ V_10 ] [ V_22 ] . V_26 ;
if ( F_4 () ) {
if ( ( V_23 == V_27 ) &&
( V_24 < V_28 ) ) {
V_14 = V_29 ;
} else if ( ( V_23 == V_29 ) &&
( V_24 > V_30 ) ) {
V_14 = V_27 ;
}
}
return F_13 ( V_1 , V_23 , V_14 , V_24 ) ;
}
static inline T_1 F_22 ( struct V_31 * V_32 )
{
int V_33 ;
for ( V_33 = 0 ; V_32 [ V_33 ] . V_26 != V_34 ; V_33 ++ )
;
return V_33 ;
}
static inline T_1 F_23 ( struct V_31 * V_32 )
{
int V_35 ;
T_2 V_36 = ~ 0 ;
for ( V_35 = 0 ; ( V_32 [ V_35 ] . V_26 != V_34 ) ; V_35 ++ )
if ( V_32 [ V_35 ] . V_26 < V_36 )
V_36 = V_32 [ V_35 ] . V_26 ;
return V_36 ;
}
static inline T_1 F_24 ( struct V_31 * V_32 )
{
int V_35 ;
T_2 V_5 = 0 ;
for ( V_35 = 0 ; ( V_32 [ V_35 ] . V_26 != V_34 ) ; V_35 ++ )
if ( V_32 [ V_35 ] . V_26 > V_5 )
V_5 = V_32 [ V_35 ] . V_26 ;
return V_5 ;
}
static int F_25 ( void )
{
int V_35 , V_4 , V_37 = 0 , V_33 = 1 ;
struct V_31 * V_32 ;
for ( V_35 = 0 ; V_35 < V_2 ; V_35 ++ )
V_33 += F_22 ( V_25 [ V_35 ] ) ;
V_32 = F_26 ( sizeof( * V_32 ) * V_33 , V_38 ) ;
if ( ! V_32 )
return - V_39 ;
V_25 [ V_2 ] = V_32 ;
for ( V_35 = V_2 - 1 ; V_35 >= 0 ; V_35 -- ) {
for ( V_4 = 0 ; V_25 [ V_35 ] [ V_4 ] . V_26 != V_34 ;
V_4 ++ ) {
V_32 [ V_37 ] . V_26 = F_11 ( V_35 ,
V_25 [ V_35 ] [ V_4 ] . V_26 ) ;
F_8 ( L_9 , V_9 , V_37 ,
V_32 [ V_37 ] . V_26 ) ;
V_37 ++ ;
}
}
V_32 [ V_37 ] . V_40 = V_37 ;
V_32 [ V_37 ] . V_26 = V_34 ;
F_8 ( L_10 , V_9 , V_32 , V_37 ) ;
return 0 ;
}
static void F_27 ( struct V_41 * V_42 )
{
T_1 V_3 = F_1 ( V_42 -> V_43 ) ;
if ( ! V_25 [ V_3 ] )
return;
F_28 ( V_12 [ V_3 ] ) ;
F_29 ( V_42 , & V_25 [ V_3 ] ) ;
F_30 ( V_42 , L_11 , V_9 , V_3 ) ;
}
static void F_31 ( struct V_41 * V_42 )
{
T_1 V_3 = F_3 ( V_42 -> V_43 ) ;
int V_35 ;
if ( F_32 ( & V_44 [ V_3 ] ) )
return;
if ( V_3 < V_2 )
return F_27 ( V_42 ) ;
F_33 (i) {
struct V_41 * V_45 = F_34 ( V_35 ) ;
if ( ! V_45 ) {
F_18 ( L_12 , V_9 , V_35 ) ;
return;
}
F_27 ( V_45 ) ;
}
F_35 ( V_25 [ V_3 ] ) ;
}
static int F_36 ( struct V_41 * V_42 )
{
T_1 V_3 = F_1 ( V_42 -> V_43 ) ;
char V_46 [ 14 ] = L_13 ;
int V_17 ;
if ( V_25 [ V_3 ] )
return 0 ;
V_17 = V_47 -> V_48 ( V_42 ) ;
if ( V_17 ) {
F_37 ( V_42 , L_14 ,
V_9 , V_42 -> V_43 , V_17 ) ;
goto V_49;
}
V_17 = F_38 ( V_42 , & V_25 [ V_3 ] ) ;
if ( V_17 ) {
F_37 ( V_42 , L_15 ,
V_9 , V_42 -> V_43 , V_17 ) ;
goto V_49;
}
V_46 [ 12 ] = V_3 + '0' ;
V_12 [ V_3 ] = F_39 ( V_42 , V_46 ) ;
if ( ! F_40 ( V_12 [ V_3 ] ) ) {
F_30 ( V_42 , L_16 ,
V_9 , V_12 [ V_3 ] , V_25 [ V_3 ] ,
V_3 ) ;
return 0 ;
}
F_37 ( V_42 , L_17 ,
V_9 , V_42 -> V_43 , V_3 ) ;
V_17 = F_41 ( V_12 [ V_3 ] ) ;
F_29 ( V_42 , & V_25 [ V_3 ] ) ;
V_49:
F_37 ( V_42 , L_18 , V_9 ,
V_3 ) ;
return V_17 ;
}
static int F_42 ( struct V_41 * V_42 )
{
T_1 V_3 = F_3 ( V_42 -> V_43 ) ;
int V_35 , V_17 ;
if ( F_43 ( & V_44 [ V_3 ] ) != 1 )
return 0 ;
if ( V_3 < V_2 ) {
V_17 = F_36 ( V_42 ) ;
if ( V_17 )
F_44 ( & V_44 [ V_3 ] ) ;
return V_17 ;
}
F_33 (i) {
struct V_41 * V_45 = F_34 ( V_35 ) ;
if ( ! V_45 ) {
F_18 ( L_12 , V_9 , V_35 ) ;
return - V_50 ;
}
V_17 = F_36 ( V_45 ) ;
if ( V_17 )
goto V_51;
}
V_17 = F_25 () ;
if ( V_17 )
goto V_51;
V_28 = F_23 ( V_25 [ 0 ] ) ;
V_30 = F_11 ( 1 , F_24 ( V_25 [ 1 ] ) ) ;
F_8 ( L_19 ,
V_9 , V_3 , V_28 , V_30 ) ;
return 0 ;
V_51:
F_33 (i) {
struct V_41 * V_45 = F_34 ( V_35 ) ;
if ( ! V_45 ) {
F_18 ( L_12 , V_9 , V_35 ) ;
return - V_50 ;
}
F_27 ( V_45 ) ;
}
F_44 ( & V_44 [ V_3 ] ) ;
return V_17 ;
}
static int F_45 ( struct V_20 * V_21 )
{
T_1 V_10 = F_3 ( V_21 -> V_1 ) ;
struct V_41 * V_42 ;
int V_17 ;
V_42 = F_34 ( V_21 -> V_1 ) ;
if ( ! V_42 ) {
F_18 ( L_12 , V_9 ,
V_21 -> V_1 ) ;
return - V_50 ;
}
V_17 = F_42 ( V_42 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_46 ( V_21 , V_25 [ V_10 ] ) ;
if ( V_17 ) {
F_37 ( V_42 , L_20 ,
V_21 -> V_1 , V_10 ) ;
F_31 ( V_42 ) ;
return V_17 ;
}
if ( V_10 < V_2 ) {
F_47 ( V_21 -> V_52 , F_48 ( V_21 -> V_1 ) ) ;
F_7 ( V_8 , V_21 -> V_1 ) = V_10 ;
} else {
F_7 ( V_8 , V_21 -> V_1 ) = V_27 ;
}
if ( V_47 -> V_53 )
V_21 -> V_54 . V_55 =
V_47 -> V_53 ( V_42 ) ;
else
V_21 -> V_54 . V_55 = V_56 ;
if ( F_4 () )
F_7 ( V_7 , V_21 -> V_1 ) = F_9 ( V_21 -> V_1 ) ;
F_49 ( V_42 , L_21 , V_9 , V_21 -> V_1 ) ;
return 0 ;
}
static int F_50 ( struct V_20 * V_21 )
{
struct V_41 * V_42 ;
V_42 = F_34 ( V_21 -> V_1 ) ;
if ( ! V_42 ) {
F_18 ( L_12 , V_9 ,
V_21 -> V_1 ) ;
return - V_50 ;
}
F_51 ( V_21 -> V_1 ) ;
F_31 ( V_42 ) ;
F_30 ( V_42 , L_22 , V_9 , V_21 -> V_1 ) ;
return 0 ;
}
static int F_52 ( struct V_57 * V_58 ,
unsigned long V_59 , void * V_60 )
{
F_8 ( L_23 , V_9 , V_59 ) ;
switch ( V_59 ) {
case V_61 :
case V_62 :
F_53 ( & V_63 ) ;
break;
case V_64 :
F_54 ( true ) ;
F_55 ( & V_63 ) ;
break;
case V_65 :
F_54 ( false ) ;
F_55 ( & V_63 ) ;
break;
default:
return V_66 ;
}
return V_67 ;
}
int F_56 ( struct V_68 * V_69 )
{
int V_17 , V_35 ;
if ( V_47 ) {
F_8 ( L_24 , V_9 ,
V_47 -> V_46 ) ;
return - V_70 ;
}
if ( ! V_69 || ! strlen ( V_69 -> V_46 ) || ! V_69 -> V_48 ) {
F_18 ( L_25 , V_9 ) ;
return - V_50 ;
}
V_47 = V_69 ;
V_17 = F_57 () ;
F_54 ( V_17 ) ;
for ( V_35 = 0 ; V_35 < V_2 ; V_35 ++ )
F_58 ( & V_19 [ V_35 ] ) ;
V_17 = F_55 ( & V_63 ) ;
if ( V_17 ) {
F_59 ( L_26 ,
V_9 , V_69 -> V_46 , V_17 ) ;
V_47 = NULL ;
} else {
V_17 = F_60 ( & V_71 ) ;
if ( V_17 ) {
F_53 ( & V_63 ) ;
V_47 = NULL ;
} else {
F_59 ( L_27 ,
V_9 , V_69 -> V_46 ) ;
}
}
F_61 () ;
return V_17 ;
}
void F_62 ( struct V_68 * V_69 )
{
if ( V_47 != V_69 ) {
F_18 ( L_28 ,
V_9 , V_47 -> V_46 ) ;
return;
}
F_57 () ;
F_63 ( & V_71 ) ;
F_53 ( & V_63 ) ;
F_61 () ;
F_59 ( L_29 , V_9 ,
V_47 -> V_46 ) ;
V_47 = NULL ;
}
