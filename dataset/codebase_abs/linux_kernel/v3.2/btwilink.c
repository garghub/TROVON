static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
switch ( V_3 ) {
case V_6 :
V_5 -> V_7 . V_8 ++ ;
break;
case V_9 :
V_5 -> V_7 . V_10 ++ ;
break;
case V_11 :
V_5 -> V_7 . V_12 ++ ;
break;
}
}
static void F_2 ( void * V_13 , char V_14 )
{
struct V_1 * V_15 = V_13 ;
V_15 -> V_16 = V_14 ;
F_3 ( & V_15 -> V_17 ) ;
}
static long F_4 ( void * V_13 , struct V_18 * V_19 )
{
struct V_1 * V_15 = V_13 ;
int V_20 ;
if ( ! V_19 )
return - V_21 ;
if ( ! V_15 ) {
F_5 ( V_19 ) ;
return - V_21 ;
}
V_19 -> V_22 = ( void * ) V_15 -> V_5 ;
V_20 = F_6 ( V_19 ) ;
if ( V_20 < 0 ) {
F_7 ( L_1 , V_20 ) ;
return V_20 ;
}
V_15 -> V_5 -> V_7 . V_23 += V_19 -> V_24 ;
return 0 ;
}
static int F_8 ( struct V_4 * V_5 )
{
unsigned long V_25 ;
struct V_1 * V_2 ;
int V_20 , V_26 ;
F_9 ( L_2 , V_5 -> V_27 , V_5 ) ;
if ( F_10 ( V_28 , & V_5 -> V_29 ) )
return - V_30 ;
V_2 = V_5 -> V_31 ;
for ( V_26 = 0 ; V_26 < V_32 ; V_26 ++ ) {
V_33 [ V_26 ] . V_13 = V_2 ;
V_33 [ V_26 ] . V_34 = V_35 ;
V_33 [ V_26 ] . V_36 = F_4 ;
V_33 [ V_26 ] . V_37 = F_2 ;
F_11 ( & V_2 -> V_17 ) ;
V_2 -> V_16 = - V_38 ;
V_20 = F_12 ( & V_33 [ V_26 ] ) ;
if ( ! V_20 )
goto V_39;
if ( V_20 != - V_38 ) {
F_13 ( V_28 , & V_5 -> V_29 ) ;
F_7 ( L_3 , V_20 ) ;
return V_20 ;
}
F_9 ( L_4
L_5 ) ;
V_25 = F_14
( & V_2 -> V_17 ,
F_15 ( V_40 ) ) ;
if ( ! V_25 ) {
F_13 ( V_28 , & V_5 -> V_29 ) ;
F_7 ( L_6
L_5 ,
V_40 / 1000 ) ;
return - V_41 ;
}
if ( V_2 -> V_16 != 0 ) {
F_13 ( V_28 , & V_5 -> V_29 ) ;
F_7 ( L_7
L_8 , V_2 -> V_16 ) ;
return - V_42 ;
}
V_39:
V_2 -> V_43 = V_33 [ V_26 ] . V_44 ;
if ( ! V_2 -> V_43 ) {
F_7 ( L_9 ) ;
F_13 ( V_28 , & V_5 -> V_29 ) ;
for ( V_26 = 0 ; V_26 < V_32 ; V_26 ++ ) {
V_20 = F_16 ( & V_33 [ V_26 ] ) ;
if ( V_20 )
F_7 ( L_10
L_11 , V_20 ) ;
V_2 -> V_43 = NULL ;
}
return - V_45 ;
}
}
return 0 ;
}
static int F_17 ( struct V_4 * V_5 )
{
int V_20 , V_26 ;
struct V_1 * V_2 = V_5 -> V_31 ;
if ( ! F_18 ( V_28 , & V_5 -> V_29 ) )
return 0 ;
for ( V_26 = V_32 - 1 ; V_26 >= 0 ; V_26 -- ) {
V_20 = F_16 ( & V_33 [ V_26 ] ) ;
if ( V_20 )
F_7 ( L_12 ,
V_33 [ V_26 ] . V_46 , V_20 ) ;
}
V_2 -> V_43 = NULL ;
return V_20 ;
}
static int F_19 ( struct V_18 * V_19 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
long V_24 ;
V_5 = (struct V_4 * ) V_19 -> V_22 ;
if ( ! F_20 ( V_28 , & V_5 -> V_29 ) )
return - V_30 ;
V_2 = V_5 -> V_31 ;
memcpy ( F_21 ( V_19 , 1 ) , & F_22 ( V_19 ) -> V_3 , 1 ) ;
F_9 ( L_13 , V_5 -> V_27 , F_22 ( V_19 ) -> V_3 ,
V_19 -> V_24 ) ;
V_24 = V_2 -> V_43 ( V_19 ) ;
if ( V_24 < 0 ) {
F_5 ( V_19 ) ;
F_7 ( L_14 , V_24 ) ;
return - V_42 ;
}
V_5 -> V_7 . V_47 += V_24 ;
F_1 ( V_2 , F_22 ( V_19 ) -> V_3 ) ;
return 0 ;
}
static void F_23 ( struct V_4 * V_5 )
{
F_9 ( L_15 , V_5 -> V_27 ) ;
}
static int F_24 ( struct V_48 * V_49 )
{
static struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_20 ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_50 ) ;
if ( ! V_2 )
return - V_51 ;
V_5 = F_26 () ;
if ( ! V_5 ) {
F_27 ( V_2 ) ;
return - V_51 ;
}
F_9 ( L_16 , V_5 ) ;
V_2 -> V_5 = V_5 ;
V_5 -> V_52 = V_53 ;
V_5 -> V_31 = V_2 ;
V_5 -> V_54 = F_8 ;
V_5 -> V_55 = F_17 ;
V_5 -> V_56 = NULL ;
V_5 -> V_57 = F_19 ;
V_5 -> V_58 = F_23 ;
V_5 -> V_59 = V_60 ;
V_20 = F_28 ( V_5 ) ;
if ( V_20 < 0 ) {
F_7 ( L_17 , V_20 ) ;
F_27 ( V_2 ) ;
F_29 ( V_5 ) ;
return V_20 ;
}
F_9 ( L_18 , V_5 ) ;
F_30 ( & V_49 -> V_22 , V_2 ) ;
return V_20 ;
}
static int F_31 ( struct V_48 * V_49 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 = F_32 ( & V_49 -> V_22 ) ;
if ( ! V_2 )
return - V_21 ;
F_9 ( L_15 , V_2 -> V_5 -> V_27 ) ;
V_5 = V_2 -> V_5 ;
F_17 ( V_5 ) ;
F_33 ( V_5 ) ;
F_29 ( V_5 ) ;
F_27 ( V_2 ) ;
F_30 ( & V_49 -> V_22 , NULL ) ;
return 0 ;
}
static int T_1 F_34 ( void )
{
F_35 ( L_19 , V_61 ) ;
return F_36 ( & V_62 ) ;
}
static void T_2 F_37 ( void )
{
F_38 ( & V_62 ) ;
}
