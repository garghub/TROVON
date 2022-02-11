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
struct V_19 * V_20 = F_6 ( V_17 ) ;
return F_7 ( V_20 -> V_22 ) & V_25 ;
}
static void F_12 ( struct V_27 * V_28 ,
void T_2 * V_29 ,
const char * V_30 )
{
const struct V_31 * V_32 = NULL ;
struct V_33 * div = NULL ;
struct V_16 * V_34 = NULL ;
if ( V_28 -> V_35 & V_36 ) {
div = F_13 ( sizeof( * div ) , V_37 ) ;
if ( ! div )
return;
div -> V_22 = V_28 -> V_7 + V_29 ;
div -> V_35 = V_38 ;
div -> V_39 = 27 ;
div -> V_40 = 1 ;
V_34 = & div -> V_17 ;
V_32 = & V_41 ;
}
V_28 -> V_20 . V_22 = V_28 -> V_7 + V_29 ;
V_28 -> V_20 . V_42 = 0 ;
V_28 -> V_1 = F_14 ( NULL , V_28 -> V_13 , & V_30 , 1 ,
NULL , NULL ,
V_34 , V_32 ,
& V_28 -> V_20 . V_17 , & V_43 , 0 ) ;
if ( F_15 ( V_28 -> V_1 ) ) {
F_16 ( div ) ;
F_17 ( L_2 , V_14 , V_28 -> V_13 ) ;
return;
}
switch ( V_28 -> V_7 ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
F_18 ( V_28 -> V_1 ) ;
}
}
static void F_19 ( void T_2 * V_29 ,
const char * V_12 )
{
const char * V_30 = V_12 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_2 ( V_10 ) ; V_8 ++ ) {
if ( strcmp ( V_10 [ V_8 ] . V_12 , V_12 ) )
continue;
F_12 ( & V_10 [ V_8 ] , V_29 ,
V_30 ) ;
if ( V_10 [ V_8 ] . V_35 & V_48 )
V_30 = V_10 [ V_8 ] . V_13 ;
}
}
static void T_3 F_20 ( struct V_49 * V_50 )
{
struct V_5 * V_6 ;
void T_2 * V_29 ;
int V_8 , V_51 ;
V_29 = F_21 ( V_50 , 0 ) ;
if ( ! V_29 ) {
F_17 ( L_3 , V_14 ) ;
return;
}
V_6 = F_13 ( sizeof( * V_6 ) , V_37 ) ;
if ( ! V_6 )
return;
V_6 -> V_11 = F_22 ( V_50 , L_4 ) ;
V_6 -> V_13 = F_23 ( V_6 -> V_11 , sizeof( char * ) , V_37 ) ;
if ( ! V_6 -> V_13 ) {
F_16 ( V_6 ) ;
return;
}
for ( V_8 = 0 ; V_8 < V_6 -> V_11 ; V_8 ++ ) {
V_51 = F_24 ( V_50 , L_4 , V_8 ,
& V_6 -> V_13 [ V_8 ] ) ;
if ( V_51 ) {
F_17 ( L_5 ,
V_14 , V_8 ) ;
continue;
}
F_19 ( V_29 , V_6 -> V_13 [ V_8 ] ) ;
}
F_25 ( V_50 , F_1 , V_6 ) ;
}
