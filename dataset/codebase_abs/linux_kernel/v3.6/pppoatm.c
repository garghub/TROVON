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
if ( F_7 ( V_14 , & V_11 -> V_15 ) )
F_8 ( & V_11 -> V_16 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_11 ;
V_11 = F_1 ( V_3 ) ;
V_3 -> V_17 = V_11 -> V_18 ;
V_3 -> V_19 = V_11 -> V_12 ;
F_10 ( & V_11 -> V_16 ) ;
F_11 ( & V_11 -> V_6 ) ;
V_3 -> V_4 = NULL ;
F_12 ( V_11 ) ;
F_13 ( V_20 ) ;
}
static void F_14 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
F_15 ( L_1 ) ;
if ( V_10 == NULL ) {
F_15 ( L_2 , V_11 ) ;
F_9 ( V_3 ) ;
V_3 -> V_17 ( V_3 , NULL ) ;
return;
}
F_16 ( V_3 , V_10 -> V_21 ) ;
switch ( V_11 -> V_22 ) {
case V_23 :
if ( V_10 -> V_24 < V_25 ||
memcmp ( V_10 -> V_26 , V_27 , V_25 ) )
goto error;
F_17 ( V_10 , V_25 ) ;
break;
case V_28 :
if ( V_11 -> V_6 . V_29 == NULL ) {
F_18 ( V_10 ) ;
return;
}
if ( V_10 -> V_24 >= sizeof( V_27 ) &&
! memcmp ( V_10 -> V_26 , V_27 , sizeof( V_27 ) ) ) {
V_11 -> V_22 = V_23 ;
F_17 ( V_10 , V_25 ) ;
break;
}
if ( V_10 -> V_24 >= ( sizeof( V_27 ) - V_25 ) &&
! memcmp ( V_10 -> V_26 , & V_27 [ V_25 ] ,
sizeof( V_27 ) - V_25 ) ) {
V_11 -> V_22 = V_30 ;
V_11 -> V_6 . V_31 += V_25 ;
break;
}
F_15 ( L_3 ,
V_10 -> V_26 [ 0 ] , V_10 -> V_26 [ 1 ] , V_10 -> V_26 [ 2 ] ,
V_10 -> V_26 [ 3 ] , V_10 -> V_26 [ 4 ] , V_10 -> V_26 [ 5 ] ) ;
goto error;
case V_30 :
break;
}
F_19 ( & V_11 -> V_6 , V_10 ) ;
return;
error:
F_18 ( V_10 ) ;
F_20 ( & V_11 -> V_6 , 0 ) ;
}
static inline int F_21 ( struct V_1 * V_11 , int V_32 )
{
if ( F_22 ( V_11 -> V_3 , V_32 ) &&
F_23 ( & V_11 -> V_13 , V_33 ) )
return 1 ;
F_24 ( V_14 , & V_11 -> V_15 ) ;
if ( F_22 ( V_11 -> V_3 , V_32 ) &&
F_25 ( & V_11 -> V_13 ) )
return 1 ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 , struct V_9 * V_10 )
{
struct V_1 * V_11 = F_2 ( V_6 ) ;
F_27 ( V_10 ) -> V_34 = V_11 -> V_3 ;
F_15 ( L_4 , V_10 , V_11 -> V_3 ) ;
if ( V_10 -> V_26 [ 0 ] == '\0' && ( V_11 -> V_35 & V_36 ) )
( void ) F_17 ( V_10 , 1 ) ;
switch ( V_11 -> V_22 ) {
case V_23 :
if ( F_28 ( V_10 ) < V_25 ) {
struct V_9 * V_37 ;
V_37 = F_29 ( V_10 , V_25 ) ;
if ( V_37 != NULL &&
! F_21 ( V_11 , V_37 -> V_21 ) ) {
F_18 ( V_37 ) ;
goto V_38;
}
F_30 ( V_10 ) ;
V_10 = V_37 ;
if ( V_10 == NULL )
return V_39 ;
} else if ( ! F_21 ( V_11 , V_10 -> V_21 ) )
goto V_38;
memcpy ( F_31 ( V_10 , V_25 ) , V_27 , V_25 ) ;
break;
case V_30 :
if ( ! F_21 ( V_11 , V_10 -> V_21 ) )
goto V_38;
break;
case V_28 :
F_15 ( L_5 ) ;
F_18 ( V_10 ) ;
return 1 ;
}
F_32 ( V_10 -> V_21 , & F_33 ( F_27 ( V_10 ) -> V_34 ) -> V_40 ) ;
F_27 ( V_10 ) -> V_41 = F_27 ( V_10 ) -> V_34 -> V_41 ;
F_15 ( L_6 ,
V_10 , F_27 ( V_10 ) -> V_34 , F_27 ( V_10 ) -> V_34 -> V_42 ) ;
return F_27 ( V_10 ) -> V_34 -> V_43 ( F_27 ( V_10 ) -> V_34 , V_10 )
? V_39 : 1 ;
V_38:
if ( ( V_11 -> V_35 & V_36 ) && F_28 ( V_10 ) > 0 &&
V_10 -> V_26 [ - 1 ] == '\0' )
( void ) F_31 ( V_10 , 1 ) ;
return 0 ;
}
static int F_34 ( struct V_5 * V_6 , unsigned int V_44 ,
unsigned long V_8 )
{
switch ( V_44 ) {
case V_45 :
return F_35 ( F_2 ( V_6 ) -> V_35 , ( int V_46 * ) V_8 )
? - V_47 : 0 ;
case V_48 :
return F_36 ( F_2 ( V_6 ) -> V_35 , ( int V_46 * ) V_8 )
? - V_47 : 0 ;
}
return - V_49 ;
}
static int F_37 ( struct V_2 * V_3 , void V_46 * V_8 )
{
struct V_50 V_51 ;
struct V_1 * V_11 ;
int V_52 ;
static const F_38 ( V_53 , F_3 , 0 ) ;
if ( F_39 ( & V_51 , V_8 , sizeof V_51 ) )
return - V_47 ;
if ( V_51 . V_22 != V_54 &&
V_51 . V_22 != V_55 && V_51 . V_22 != V_56 )
return - V_57 ;
V_11 = F_40 ( sizeof( * V_11 ) , V_58 ) ;
if ( V_11 == NULL )
return - V_59 ;
V_11 -> V_3 = V_3 ;
F_41 ( & V_11 -> V_13 , V_33 ) ;
V_11 -> V_18 = V_3 -> V_17 ;
V_11 -> V_12 = V_3 -> V_19 ;
V_11 -> V_22 = (enum V_60 ) V_51 . V_22 ;
V_11 -> V_6 . V_7 = V_11 ;
V_11 -> V_6 . V_61 = & V_62 ;
V_11 -> V_6 . V_31 = V_3 -> V_63 . V_64 . V_65 - V_66 -
( V_51 . V_22 == V_30 ? 0 : V_25 ) ;
V_11 -> V_16 = V_53 ;
V_11 -> V_16 . V_26 = ( unsigned long ) & V_11 -> V_6 ;
V_52 = F_42 ( & V_11 -> V_6 ) ;
if ( V_52 != 0 ) {
F_12 ( V_11 ) ;
return V_52 ;
}
V_3 -> V_4 = V_11 ;
V_3 -> V_17 = F_14 ;
V_3 -> V_19 = F_5 ;
F_43 ( V_20 ) ;
F_44 ( V_3 ) ;
return 0 ;
}
static int F_45 ( struct V_67 * V_68 , unsigned int V_44 ,
unsigned long V_8 )
{
struct V_2 * V_3 = F_46 ( V_68 ) ;
void V_46 * V_69 = ( void V_46 * ) V_8 ;
if ( V_44 != V_70 && V_3 -> V_17 != F_14 )
return - V_71 ;
switch ( V_44 ) {
case V_70 : {
T_1 V_72 ;
if ( F_36 ( V_72 , ( T_1 V_46 * ) V_69 ) )
return - V_47 ;
if ( V_72 != V_73 )
return - V_71 ;
if ( ! F_47 ( V_74 ) )
return - V_75 ;
return F_37 ( V_3 , V_69 ) ;
}
case V_76 :
return F_35 ( F_48 ( & F_1 ( V_3 ) ->
V_6 ) , ( int V_46 * ) V_69 ) ? - V_47 : 0 ;
case V_77 :
return F_35 ( F_49 ( & F_1 ( V_3 ) ->
V_6 ) , ( int V_46 * ) V_69 ) ? - V_47 : 0 ;
}
return - V_71 ;
}
static int T_2 F_50 ( void )
{
F_51 ( & V_78 ) ;
return 0 ;
}
static void T_3 F_52 ( void )
{
F_53 ( & V_78 ) ;
}
