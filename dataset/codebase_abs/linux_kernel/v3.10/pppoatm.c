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
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( F_6 ( V_10 , & V_9 -> V_11 ) )
F_7 ( & V_9 -> V_12 ) ;
if ( V_9 -> V_13 )
V_9 -> V_13 ( V_3 ) ;
}
static void F_8 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
V_9 -> V_16 ( V_3 , V_15 ) ;
F_9 ( & V_9 -> V_17 ) ;
if ( F_6 ( V_10 , & V_9 -> V_11 ) )
F_7 ( & V_9 -> V_12 ) ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
V_9 = F_1 ( V_3 ) ;
V_3 -> V_18 = V_9 -> V_19 ;
V_3 -> V_20 = V_9 -> V_16 ;
V_3 -> V_21 = V_9 -> V_13 ;
F_11 ( & V_9 -> V_12 ) ;
F_12 ( & V_9 -> V_6 ) ;
V_3 -> V_4 = NULL ;
F_13 ( V_9 ) ;
}
static void F_14 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_15 ( L_1 ) ;
if ( V_15 == NULL ) {
struct V_22 * V_22 ;
F_15 ( L_2 , V_9 ) ;
V_22 = V_9 -> V_23 ;
F_10 ( V_3 ) ;
V_3 -> V_18 ( V_3 , NULL ) ;
F_16 ( V_22 ) ;
return;
}
F_17 ( V_3 , V_15 -> V_24 ) ;
switch ( V_9 -> V_25 ) {
case V_26 :
if ( V_15 -> V_27 < V_28 ||
memcmp ( V_15 -> V_29 , V_30 , V_28 ) )
goto error;
F_18 ( V_15 , V_28 ) ;
break;
case V_31 :
if ( V_9 -> V_6 . V_32 == NULL ) {
F_19 ( V_15 ) ;
return;
}
if ( V_15 -> V_27 >= sizeof( V_30 ) &&
! memcmp ( V_15 -> V_29 , V_30 , sizeof( V_30 ) ) ) {
V_9 -> V_25 = V_26 ;
F_18 ( V_15 , V_28 ) ;
break;
}
if ( V_15 -> V_27 >= ( sizeof( V_30 ) - V_28 ) &&
! memcmp ( V_15 -> V_29 , & V_30 [ V_28 ] ,
sizeof( V_30 ) - V_28 ) ) {
V_9 -> V_25 = V_33 ;
V_9 -> V_6 . V_34 += V_28 ;
break;
}
F_15 ( L_3 ,
V_15 -> V_29 [ 0 ] , V_15 -> V_29 [ 1 ] , V_15 -> V_29 [ 2 ] ,
V_15 -> V_29 [ 3 ] , V_15 -> V_29 [ 4 ] , V_15 -> V_29 [ 5 ] ) ;
goto error;
case V_33 :
break;
}
F_20 ( & V_9 -> V_6 , V_15 ) ;
return;
error:
F_19 ( V_15 ) ;
F_21 ( & V_9 -> V_6 , 0 ) ;
}
static int F_22 ( struct V_1 * V_9 , int V_35 )
{
if ( F_23 ( V_9 -> V_3 , V_35 ) &&
F_24 ( & V_9 -> V_17 , V_36 ) )
return 1 ;
F_25 ( V_10 , & V_9 -> V_11 ) ;
if ( F_23 ( V_9 -> V_3 , V_35 ) &&
F_26 ( & V_9 -> V_17 ) )
return 1 ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_1 * V_9 = F_2 ( V_6 ) ;
struct V_2 * V_37 ;
int V_38 ;
F_28 ( V_15 ) -> V_37 = V_9 -> V_3 ;
F_15 ( L_4 , V_15 , V_9 -> V_3 ) ;
if ( V_15 -> V_29 [ 0 ] == '\0' && ( V_9 -> V_39 & V_40 ) )
( void ) F_18 ( V_15 , 1 ) ;
V_37 = F_28 ( V_15 ) -> V_37 ;
F_29 ( F_30 ( V_37 ) ) ;
if ( F_31 ( F_30 ( V_37 ) ) ) {
F_25 ( V_10 , & V_9 -> V_11 ) ;
goto V_41;
}
if ( F_32 ( V_42 , & V_37 -> V_39 ) ||
F_32 ( V_43 , & V_37 -> V_39 ) ||
! F_32 ( V_44 , & V_37 -> V_39 ) ) {
F_33 ( F_30 ( V_37 ) ) ;
F_19 ( V_15 ) ;
return V_45 ;
}
switch ( V_9 -> V_25 ) {
case V_26 :
if ( F_34 ( V_15 ) < V_28 ) {
struct V_14 * V_46 ;
V_46 = F_35 ( V_15 , V_28 ) ;
if ( V_46 != NULL &&
! F_22 ( V_9 , V_46 -> V_24 ) ) {
F_19 ( V_46 ) ;
goto V_41;
}
F_36 ( V_15 ) ;
V_15 = V_46 ;
if ( V_15 == NULL ) {
F_33 ( F_30 ( V_37 ) ) ;
return V_45 ;
}
} else if ( ! F_22 ( V_9 , V_15 -> V_24 ) )
goto V_41;
memcpy ( F_37 ( V_15 , V_28 ) , V_30 , V_28 ) ;
break;
case V_33 :
if ( ! F_22 ( V_9 , V_15 -> V_24 ) )
goto V_41;
break;
case V_31 :
F_33 ( F_30 ( V_37 ) ) ;
F_15 ( L_5 ) ;
F_19 ( V_15 ) ;
return 1 ;
}
F_38 ( V_15 -> V_24 , & F_30 ( F_28 ( V_15 ) -> V_37 ) -> V_47 ) ;
F_28 ( V_15 ) -> V_48 = F_28 ( V_15 ) -> V_37 -> V_48 ;
F_15 ( L_6 ,
V_15 , F_28 ( V_15 ) -> V_37 , F_28 ( V_15 ) -> V_37 -> V_49 ) ;
V_38 = F_28 ( V_15 ) -> V_37 -> V_50 ( F_28 ( V_15 ) -> V_37 , V_15 )
? V_45 : 1 ;
F_33 ( F_30 ( V_37 ) ) ;
return V_38 ;
V_41:
F_33 ( F_30 ( V_37 ) ) ;
if ( ( V_9 -> V_39 & V_40 ) && F_34 ( V_15 ) > 0 &&
V_15 -> V_29 [ - 1 ] == '\0' )
( void ) F_37 ( V_15 , 1 ) ;
return 0 ;
}
static int F_39 ( struct V_5 * V_6 , unsigned int V_51 ,
unsigned long V_8 )
{
switch ( V_51 ) {
case V_52 :
return F_40 ( F_2 ( V_6 ) -> V_39 , ( int V_53 * ) V_8 )
? - V_54 : 0 ;
case V_55 :
return F_41 ( F_2 ( V_6 ) -> V_39 , ( int V_53 * ) V_8 )
? - V_54 : 0 ;
}
return - V_56 ;
}
static int F_42 ( struct V_2 * V_3 , void V_53 * V_8 )
{
struct V_57 V_58 ;
struct V_1 * V_9 ;
int V_59 ;
static const F_43 ( V_60 , F_3 , 0 ) ;
if ( F_44 ( & V_58 , V_8 , sizeof V_58 ) )
return - V_54 ;
if ( V_58 . V_25 != V_61 &&
V_58 . V_25 != V_62 && V_58 . V_25 != V_63 )
return - V_64 ;
V_9 = F_45 ( sizeof( * V_9 ) , V_65 ) ;
if ( V_9 == NULL )
return - V_66 ;
V_9 -> V_3 = V_3 ;
F_46 ( & V_9 -> V_17 , V_36 ) ;
V_9 -> V_19 = V_3 -> V_18 ;
V_9 -> V_16 = V_3 -> V_20 ;
V_9 -> V_23 = V_3 -> V_67 ;
V_9 -> V_13 = V_3 -> V_21 ;
V_9 -> V_25 = (enum V_68 ) V_58 . V_25 ;
V_9 -> V_6 . V_7 = V_9 ;
V_9 -> V_6 . V_69 = & V_70 ;
V_9 -> V_6 . V_34 = V_3 -> V_71 . V_72 . V_73 - V_74 -
( V_58 . V_25 == V_33 ? 0 : V_28 ) ;
V_9 -> V_12 = V_60 ;
V_9 -> V_12 . V_29 = ( unsigned long ) & V_9 -> V_6 ;
V_59 = F_47 ( & V_9 -> V_6 ) ;
if ( V_59 != 0 ) {
F_13 ( V_9 ) ;
return V_59 ;
}
V_3 -> V_4 = V_9 ;
V_3 -> V_18 = F_14 ;
V_3 -> V_20 = F_8 ;
V_3 -> V_21 = F_5 ;
F_48 ( V_75 ) ;
V_3 -> V_67 = V_75 ;
F_49 ( V_3 ) ;
return 0 ;
}
static int F_50 ( struct V_76 * V_77 , unsigned int V_51 ,
unsigned long V_8 )
{
struct V_2 * V_3 = F_51 ( V_77 ) ;
void V_53 * V_78 = ( void V_53 * ) V_8 ;
if ( V_51 != V_79 && V_3 -> V_18 != F_14 )
return - V_80 ;
switch ( V_51 ) {
case V_79 : {
T_1 V_81 ;
if ( F_41 ( V_81 , ( T_1 V_53 * ) V_78 ) )
return - V_54 ;
if ( V_81 != V_82 )
return - V_80 ;
if ( ! F_52 ( V_83 ) )
return - V_84 ;
if ( V_77 -> V_85 != V_86 )
return - V_64 ;
return F_42 ( V_3 , V_78 ) ;
}
case V_87 :
return F_40 ( F_53 ( & F_1 ( V_3 ) ->
V_6 ) , ( int V_53 * ) V_78 ) ? - V_54 : 0 ;
case V_88 :
return F_40 ( F_54 ( & F_1 ( V_3 ) ->
V_6 ) , ( int V_53 * ) V_78 ) ? - V_54 : 0 ;
}
return - V_80 ;
}
static int T_2 F_55 ( void )
{
F_56 ( & V_89 ) ;
return 0 ;
}
static void T_3 F_57 ( void )
{
F_58 ( & V_89 ) ;
}
