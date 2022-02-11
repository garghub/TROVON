static struct V_1 * F_1 ( struct V_2 * V_3 ,
void * V_4 )
{
struct V_5 * V_6 = V_4 ;
unsigned int V_7 = V_3 -> args [ 0 ] ;
int V_8 , V_9 ;
for ( V_8 = 0 ; V_8 < F_2 ( V_10 ) ; V_8 ++ ) {
if ( V_10 [ V_8 ] . V_7 != V_7 )
continue;
for ( V_9 = 0 ; V_9 < V_6 -> V_11 ; V_9 ++ ) {
if ( ! strcmp ( V_10 [ V_8 ] . V_12 , V_6 -> V_13 [ V_9 ] ) )
return V_10 [ V_8 ] . V_1 ;
}
}
F_3 ( L_1 , V_14 , V_7 ) ;
return F_4 ( - V_15 ) ;
}
static int F_5 ( struct V_16 * V_17 , bool V_18 )
{
struct V_19 * V_20 = F_6 ( V_17 ) ;
T_1 V_21 ;
V_21 = F_7 ( V_20 -> V_22 ) ;
if ( V_21 & V_23 )
V_21 |= V_24 ;
if ( V_18 ) {
V_21 |= V_25 ;
} else {
V_21 |= V_26 ;
F_8 ( V_21 , V_20 -> V_22 ) ;
V_21 &= ~ V_25 ;
}
F_8 ( V_21 , V_20 -> V_22 ) ;
return 0 ;
}
static int F_9 ( struct V_16 * V_17 )
{
return F_5 ( V_17 , true ) ;
}
static void F_10 ( struct V_16 * V_17 )
{
F_5 ( V_17 , false ) ;
}
static int F_11 ( struct V_16 * V_17 )
{
const struct V_16 * V_27 ;
V_27 = F_12 ( V_17 ) ;
if ( ! V_27 )
return 0 ;
if ( ! F_13 ( V_27 ) )
return 0 ;
return V_28 . V_29 ( V_17 ) ;
}
static void F_14 ( struct V_30 * V_31 ,
void T_2 * V_32 ,
const char * V_27 )
{
const struct V_33 * V_34 = NULL ;
struct V_35 * div = NULL ;
struct V_16 * V_36 = NULL ;
if ( V_31 -> V_37 & V_38 ) {
div = F_15 ( sizeof( * div ) , V_39 ) ;
if ( ! div )
return;
div -> V_22 = V_31 -> V_7 + V_32 ;
div -> V_37 = V_40 ;
div -> V_41 = 27 ;
div -> V_42 = 1 ;
V_36 = & div -> V_17 ;
V_34 = & V_43 ;
}
V_31 -> V_20 . V_22 = V_31 -> V_7 + V_32 ;
V_31 -> V_20 . V_44 = 0 ;
V_31 -> V_1 = F_16 ( NULL , V_31 -> V_13 , & V_27 , 1 ,
NULL , NULL ,
V_36 , V_34 ,
& V_31 -> V_20 . V_17 , & V_45 , 0 ) ;
if ( F_17 ( V_31 -> V_1 ) ) {
F_18 ( div ) ;
F_19 ( L_2 , V_14 , V_31 -> V_13 ) ;
return;
}
switch ( V_31 -> V_7 ) {
case V_46 :
case V_47 :
case V_48 :
case V_49 :
F_20 ( V_31 -> V_1 ) ;
}
}
static void F_21 ( void T_2 * V_32 ,
const char * V_12 )
{
const char * V_27 = V_12 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_2 ( V_10 ) ; V_8 ++ ) {
if ( strcmp ( V_10 [ V_8 ] . V_12 , V_12 ) )
continue;
F_14 ( & V_10 [ V_8 ] , V_32 ,
V_27 ) ;
if ( V_10 [ V_8 ] . V_37 & V_50 )
V_27 = V_10 [ V_8 ] . V_13 ;
}
}
static void T_3 F_22 ( struct V_51 * V_52 )
{
struct V_5 * V_6 ;
void T_2 * V_32 ;
int V_8 , V_53 ;
V_32 = F_23 ( V_52 , 0 ) ;
if ( ! V_32 ) {
F_19 ( L_3 , V_14 ) ;
return;
}
V_6 = F_15 ( sizeof( * V_6 ) , V_39 ) ;
if ( ! V_6 )
return;
V_6 -> V_11 = F_24 ( V_52 , L_4 ) ;
V_6 -> V_13 = F_25 ( V_6 -> V_11 , sizeof( char * ) , V_39 ) ;
if ( ! V_6 -> V_13 ) {
F_18 ( V_6 ) ;
return;
}
for ( V_8 = 0 ; V_8 < V_6 -> V_11 ; V_8 ++ ) {
V_53 = F_26 ( V_52 , L_4 , V_8 ,
& V_6 -> V_13 [ V_8 ] ) ;
if ( V_53 ) {
F_19 ( L_5 ,
V_14 , V_8 ) ;
continue;
}
F_21 ( V_32 , V_6 -> V_13 [ V_8 ] ) ;
}
F_27 ( V_52 , F_1 , V_6 ) ;
}
