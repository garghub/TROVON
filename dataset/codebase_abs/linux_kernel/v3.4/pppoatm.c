static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) ( V_3 -> V_4 ) ;
}
static inline struct V_1 * F_2 ( const struct V_5 * V_6 )
{
return (struct V_1 * ) ( V_6 -> V_7 ) ;
}
static void F_3 ( unsigned long V_8 )
{
F_4 ( (struct V_5 * ) V_8 ) ;
}
static void F_5 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
V_11 -> V_12 ( V_3 , V_10 ) ;
F_6 ( & V_11 -> V_13 ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_11 ;
V_11 = F_1 ( V_3 ) ;
V_3 -> V_14 = V_11 -> V_15 ;
V_3 -> V_16 = V_11 -> V_12 ;
F_8 ( & V_11 -> V_13 ) ;
F_9 ( & V_11 -> V_6 ) ;
V_3 -> V_4 = NULL ;
F_10 ( V_11 ) ;
F_11 ( V_17 ) ;
}
static void F_12 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
F_13 ( L_1 ) ;
if ( V_10 == NULL ) {
F_13 ( L_2 , V_11 ) ;
F_7 ( V_3 ) ;
V_3 -> V_14 ( V_3 , NULL ) ;
return;
}
F_14 ( V_3 , V_10 -> V_18 ) ;
switch ( V_11 -> V_19 ) {
case V_20 :
if ( V_10 -> V_21 < V_22 ||
memcmp ( V_10 -> V_23 , V_24 , V_22 ) )
goto error;
F_15 ( V_10 , V_22 ) ;
break;
case V_25 :
if ( V_11 -> V_6 . V_26 == NULL ) {
F_16 ( V_10 ) ;
return;
}
if ( V_10 -> V_21 >= sizeof( V_24 ) &&
! memcmp ( V_10 -> V_23 , V_24 , sizeof( V_24 ) ) ) {
V_11 -> V_19 = V_20 ;
F_15 ( V_10 , V_22 ) ;
break;
}
if ( V_10 -> V_21 >= ( sizeof( V_24 ) - V_22 ) &&
! memcmp ( V_10 -> V_23 , & V_24 [ V_22 ] ,
sizeof( V_24 ) - V_22 ) ) {
V_11 -> V_19 = V_27 ;
V_11 -> V_6 . V_28 += V_22 ;
break;
}
F_13 ( L_3 ,
V_10 -> V_23 [ 0 ] , V_10 -> V_23 [ 1 ] , V_10 -> V_23 [ 2 ] ,
V_10 -> V_23 [ 3 ] , V_10 -> V_23 [ 4 ] , V_10 -> V_23 [ 5 ] ) ;
goto error;
case V_27 :
break;
}
F_17 ( & V_11 -> V_6 , V_10 ) ;
return;
error:
F_16 ( V_10 ) ;
F_18 ( & V_11 -> V_6 , 0 ) ;
}
static int F_19 ( struct V_5 * V_6 , struct V_9 * V_10 )
{
struct V_1 * V_11 = F_2 ( V_6 ) ;
F_20 ( V_10 ) -> V_29 = V_11 -> V_3 ;
F_13 ( L_4 , V_10 , V_11 -> V_3 ) ;
if ( V_10 -> V_23 [ 0 ] == '\0' && ( V_11 -> V_30 & V_31 ) )
( void ) F_15 ( V_10 , 1 ) ;
switch ( V_11 -> V_19 ) {
case V_20 :
if ( F_21 ( V_10 ) < V_22 ) {
struct V_9 * V_32 ;
V_32 = F_22 ( V_10 , V_22 ) ;
if ( V_32 != NULL &&
! F_23 ( V_11 -> V_3 , V_32 -> V_18 ) ) {
F_16 ( V_32 ) ;
goto V_33;
}
F_16 ( V_10 ) ;
V_10 = V_32 ;
if ( V_10 == NULL )
return V_34 ;
} else if ( ! F_23 ( V_11 -> V_3 , V_10 -> V_18 ) )
goto V_33;
memcpy ( F_24 ( V_10 , V_22 ) , V_24 , V_22 ) ;
break;
case V_27 :
if ( ! F_23 ( V_11 -> V_3 , V_10 -> V_18 ) )
goto V_33;
break;
case V_25 :
F_13 ( L_5 ) ;
F_16 ( V_10 ) ;
return 1 ;
}
F_25 ( V_10 -> V_18 , & F_26 ( F_20 ( V_10 ) -> V_29 ) -> V_35 ) ;
F_20 ( V_10 ) -> V_36 = F_20 ( V_10 ) -> V_29 -> V_36 ;
F_13 ( L_6 ,
V_10 , F_20 ( V_10 ) -> V_29 , F_20 ( V_10 ) -> V_29 -> V_37 ) ;
return F_20 ( V_10 ) -> V_29 -> V_38 ( F_20 ( V_10 ) -> V_29 , V_10 )
? V_34 : 1 ;
V_33:
if ( ( V_11 -> V_30 & V_31 ) && F_21 ( V_10 ) > 0 &&
V_10 -> V_23 [ - 1 ] == '\0' )
( void ) F_24 ( V_10 , 1 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 , unsigned int V_39 ,
unsigned long V_8 )
{
switch ( V_39 ) {
case V_40 :
return F_28 ( F_2 ( V_6 ) -> V_30 , ( int V_41 * ) V_8 )
? - V_42 : 0 ;
case V_43 :
return F_29 ( F_2 ( V_6 ) -> V_30 , ( int V_41 * ) V_8 )
? - V_42 : 0 ;
}
return - V_44 ;
}
static int F_30 ( struct V_2 * V_3 , void V_41 * V_8 )
{
struct V_45 V_46 ;
struct V_1 * V_11 ;
int V_47 ;
static const F_31 ( V_48 , F_3 , 0 ) ;
if ( F_32 ( & V_46 , V_8 , sizeof V_46 ) )
return - V_42 ;
if ( V_46 . V_19 != V_49 &&
V_46 . V_19 != V_50 && V_46 . V_19 != V_51 )
return - V_52 ;
V_11 = F_33 ( sizeof( * V_11 ) , V_53 ) ;
if ( V_11 == NULL )
return - V_54 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_15 = V_3 -> V_14 ;
V_11 -> V_12 = V_3 -> V_16 ;
V_11 -> V_19 = (enum V_55 ) V_46 . V_19 ;
V_11 -> V_6 . V_7 = V_11 ;
V_11 -> V_6 . V_56 = & V_57 ;
V_11 -> V_6 . V_28 = V_3 -> V_58 . V_59 . V_60 - V_61 -
( V_46 . V_19 == V_27 ? 0 : V_22 ) ;
V_11 -> V_13 = V_48 ;
V_11 -> V_13 . V_23 = ( unsigned long ) & V_11 -> V_6 ;
V_47 = F_34 ( & V_11 -> V_6 ) ;
if ( V_47 != 0 ) {
F_10 ( V_11 ) ;
return V_47 ;
}
V_3 -> V_4 = V_11 ;
V_3 -> V_14 = F_12 ;
V_3 -> V_16 = F_5 ;
F_35 ( V_17 ) ;
F_36 ( V_3 ) ;
return 0 ;
}
static int F_37 ( struct V_62 * V_63 , unsigned int V_39 ,
unsigned long V_8 )
{
struct V_2 * V_3 = F_38 ( V_63 ) ;
void V_41 * V_64 = ( void V_41 * ) V_8 ;
if ( V_39 != V_65 && V_3 -> V_14 != F_12 )
return - V_66 ;
switch ( V_39 ) {
case V_65 : {
T_1 V_67 ;
if ( F_29 ( V_67 , ( T_1 V_41 * ) V_64 ) )
return - V_42 ;
if ( V_67 != V_68 )
return - V_66 ;
if ( ! F_39 ( V_69 ) )
return - V_70 ;
return F_30 ( V_3 , V_64 ) ;
}
case V_71 :
return F_28 ( F_40 ( & F_1 ( V_3 ) ->
V_6 ) , ( int V_41 * ) V_64 ) ? - V_42 : 0 ;
case V_72 :
return F_28 ( F_41 ( & F_1 ( V_3 ) ->
V_6 ) , ( int V_41 * ) V_64 ) ? - V_42 : 0 ;
}
return - V_66 ;
}
static int T_2 F_42 ( void )
{
F_43 ( & V_73 ) ;
return 0 ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_73 ) ;
}
