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
V_20 = F_6 ( V_15 -> V_5 , V_19 ) ;
if ( V_20 < 0 ) {
F_7 ( L_1 , V_20 ) ;
return V_20 ;
}
V_15 -> V_5 -> V_7 . V_22 += V_19 -> V_23 ;
return 0 ;
}
static int F_8 ( struct V_4 * V_5 )
{
unsigned long V_24 ;
struct V_1 * V_2 ;
int V_20 , V_25 ;
F_9 ( L_2 , V_5 -> V_26 , V_5 ) ;
if ( F_10 ( V_27 , & V_5 -> V_28 ) )
return - V_29 ;
V_2 = F_11 ( V_5 ) ;
for ( V_25 = 0 ; V_25 < V_30 ; V_25 ++ ) {
V_31 [ V_25 ] . V_13 = V_2 ;
V_31 [ V_25 ] . V_32 = V_33 ;
V_31 [ V_25 ] . V_34 = F_4 ;
V_31 [ V_25 ] . V_35 = F_2 ;
F_12 ( & V_2 -> V_17 ) ;
V_2 -> V_16 = - V_36 ;
V_20 = F_13 ( & V_31 [ V_25 ] ) ;
if ( ! V_20 )
goto V_37;
if ( V_20 != - V_36 ) {
F_14 ( V_27 , & V_5 -> V_28 ) ;
F_7 ( L_3 , V_20 ) ;
return V_20 ;
}
F_9 ( L_4
L_5 ) ;
V_24 = F_15
( & V_2 -> V_17 ,
F_16 ( V_38 ) ) ;
if ( ! V_24 ) {
F_14 ( V_27 , & V_5 -> V_28 ) ;
F_7 ( L_6
L_5 ,
V_38 / 1000 ) ;
return - V_39 ;
}
if ( V_2 -> V_16 != 0 ) {
F_14 ( V_27 , & V_5 -> V_28 ) ;
F_7 ( L_7
L_8 , V_2 -> V_16 ) ;
return - V_40 ;
}
V_37:
V_2 -> V_41 = V_31 [ V_25 ] . V_42 ;
if ( ! V_2 -> V_41 ) {
F_7 ( L_9 ) ;
F_14 ( V_27 , & V_5 -> V_28 ) ;
for ( V_25 = 0 ; V_25 < V_30 ; V_25 ++ ) {
V_20 = F_17 ( & V_31 [ V_25 ] ) ;
if ( V_20 )
F_7 ( L_10
L_11 , V_20 ) ;
V_2 -> V_41 = NULL ;
}
return - V_43 ;
}
}
return 0 ;
}
static int F_18 ( struct V_4 * V_5 )
{
int V_20 , V_25 ;
struct V_1 * V_2 = F_11 ( V_5 ) ;
if ( ! F_19 ( V_27 , & V_5 -> V_28 ) )
return 0 ;
for ( V_25 = V_30 - 1 ; V_25 >= 0 ; V_25 -- ) {
V_20 = F_17 ( & V_31 [ V_25 ] ) ;
if ( V_20 )
F_7 ( L_12 ,
V_31 [ V_25 ] . V_44 , V_20 ) ;
}
V_2 -> V_41 = NULL ;
return V_20 ;
}
static int F_20 ( struct V_4 * V_5 , struct V_18 * V_19 )
{
struct V_1 * V_2 ;
long V_23 ;
if ( ! F_21 ( V_27 , & V_5 -> V_28 ) )
return - V_29 ;
V_2 = F_11 ( V_5 ) ;
memcpy ( F_22 ( V_19 , 1 ) , & F_23 ( V_19 ) -> V_3 , 1 ) ;
F_9 ( L_13 , V_5 -> V_26 , F_23 ( V_19 ) -> V_3 ,
V_19 -> V_23 ) ;
V_23 = V_2 -> V_41 ( V_19 ) ;
if ( V_23 < 0 ) {
F_5 ( V_19 ) ;
F_7 ( L_14 , V_23 ) ;
return - V_40 ;
}
V_5 -> V_7 . V_45 += V_23 ;
F_1 ( V_2 , F_23 ( V_19 ) -> V_3 ) ;
return 0 ;
}
static int F_24 ( struct V_46 * V_47 )
{
static struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_20 ;
V_2 = F_25 ( & V_47 -> V_48 , sizeof( struct V_1 ) , V_49 ) ;
if ( ! V_2 )
return - V_50 ;
V_5 = F_26 () ;
if ( ! V_5 )
return - V_50 ;
F_9 ( L_15 , V_5 ) ;
V_2 -> V_5 = V_5 ;
V_5 -> V_51 = V_52 ;
F_27 ( V_5 , V_2 ) ;
V_5 -> V_53 = F_8 ;
V_5 -> V_54 = F_18 ;
V_5 -> V_55 = NULL ;
V_5 -> V_56 = F_20 ;
V_20 = F_28 ( V_5 ) ;
if ( V_20 < 0 ) {
F_7 ( L_16 , V_20 ) ;
F_29 ( V_5 ) ;
return V_20 ;
}
F_9 ( L_17 , V_5 ) ;
F_30 ( & V_47 -> V_48 , V_2 ) ;
return V_20 ;
}
static int F_31 ( struct V_46 * V_47 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 = F_32 ( & V_47 -> V_48 ) ;
if ( ! V_2 )
return - V_21 ;
F_9 ( L_18 , V_2 -> V_5 -> V_26 ) ;
V_5 = V_2 -> V_5 ;
F_18 ( V_5 ) ;
F_33 ( V_5 ) ;
F_29 ( V_5 ) ;
F_30 ( & V_47 -> V_48 , NULL ) ;
return 0 ;
}
