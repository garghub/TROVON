static void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
F_3 ( V_3 , V_4 ) ;
F_4 ( & V_5 , & V_3 ) ;
while ( ! V_6 ) {
F_5 ( V_7 ) ;
F_6 ( L_1 ) ;
F_7 () ;
}
V_4 -> V_8 = V_9 ;
F_8 ( & V_5 , & V_3 ) ;
#else
if ( ! V_6 ) {
F_6 ( L_2 ) ;
F_9 ( V_2 ) ;
return;
}
#endif
F_10 ( V_6 , V_2 -> V_10 ) ;
F_11 ( & F_12 ( V_6 ) -> V_11 , V_2 ) ;
F_12 ( V_6 ) -> F_13 ( F_12 ( V_6 ) , V_2 -> V_12 ) ;
}
static void F_14 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_1 * V_2 ;
if ( F_15 ( V_17 , & V_14 -> V_18 ) ||
! F_15 ( V_19 , & V_14 -> V_18 ) )
return;
V_16 -> type = V_20 ;
if ( ! V_14 -> V_21 -> V_22 -> V_23 )
V_16 -> V_24 = - V_25 ;
else {
V_16 -> V_24 = V_14 -> V_21 -> V_22 -> V_23 ( V_14 , & V_16 -> V_26 ,
V_16 -> V_24 ) ;
if ( ! V_16 -> V_24 )
V_16 -> type = V_27 ;
}
while ( ! ( V_2 = F_16 ( sizeof( struct V_15 ) , V_28 ) ) )
F_7 () ;
* (struct V_15 * ) F_17 ( V_2 , sizeof( struct V_15 ) ) = * V_16 ;
F_1 ( V_2 ) ;
}
static int F_18 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_13 * V_29 ;
struct V_30 * V_31 ;
V_16 = (struct V_15 * ) V_2 -> V_32 ;
F_19 ( V_2 -> V_10 , & F_12 ( V_14 ) -> V_33 ) ;
V_14 = * (struct V_13 * * ) & V_16 -> V_14 ;
F_6 ( L_3 , ( int ) V_16 -> type , ( unsigned long ) V_14 ) ;
V_31 = F_12 ( V_14 ) ;
switch ( V_16 -> type ) {
case V_27 :
V_31 -> V_34 = - V_16 -> V_24 ;
F_20 ( V_35 , & V_14 -> V_18 ) ;
if ( ! * V_14 -> V_36 . V_37 . V_38 && ! * V_14 -> V_36 . V_37 . V_39 ) {
V_14 -> V_36 . V_40 = V_41 ;
memcpy ( V_14 -> V_36 . V_37 . V_38 ,
V_16 -> V_36 . V_37 . V_38 , V_42 ) ;
memcpy ( V_14 -> V_36 . V_37 . V_39 ,
V_16 -> V_36 . V_37 . V_39 , V_43 + 1 ) ;
}
V_29 = V_14 -> V_44 ? V_14 -> V_44 : V_14 ;
if ( V_29 -> V_45 || V_29 -> V_46 )
break;
V_29 -> V_47 = V_16 -> V_48 . V_49 . V_47 ;
V_29 -> V_45 = V_16 -> V_48 . V_49 . V_45 ;
V_29 -> V_46 = V_16 -> V_48 . V_49 . V_46 ;
if ( V_29 -> V_45 || V_29 -> V_46 )
V_29 -> V_26 = V_16 -> V_26 ;
break;
case V_20 :
F_20 ( V_50 , & V_14 -> V_18 ) ;
F_20 ( V_19 , & V_14 -> V_18 ) ;
V_31 -> V_34 = - V_16 -> V_24 ;
F_20 ( V_35 , & V_14 -> V_18 ) ;
break;
case V_51 :
V_14 = * (struct V_13 * * ) & V_16 -> V_52 ;
V_31 = F_12 ( V_14 ) ;
F_6 ( L_4 ) ;
F_21 ( V_31 ) ;
if ( F_22 ( V_31 ) ) {
F_23 ( NULL , V_53 , V_14 , NULL , NULL ) ;
F_24 ( V_2 ) ;
goto V_54;
}
V_31 -> V_55 ++ ;
F_11 ( & V_31 -> V_11 , V_2 ) ;
F_6 ( L_5 , F_25 ( V_31 ) ) ;
V_31 -> V_56 ( V_31 ) ;
V_54:
F_26 ( V_31 ) ;
return 0 ;
case V_57 :
F_27 ( V_17 , & V_14 -> V_18 ) ;
F_28 ( V_14 , V_16 -> V_24 ) ;
goto V_58;
case V_59 :
F_14 ( V_14 , V_16 ) ;
break;
case V_60 :
case V_61 :
V_31 -> V_62 = V_16 -> V_24 ;
F_20 ( V_35 , & V_14 -> V_18 ) ;
break;
default:
F_29 ( L_6 , ( int ) V_16 -> type ) ;
return - V_63 ;
}
V_31 -> V_56 ( V_31 ) ;
V_58:
F_24 ( V_2 ) ;
return 0 ;
}
void F_30 ( struct V_13 * V_14 , enum V_64 type ,
struct V_13 * V_52 , const struct V_65 * V_48 ,
const struct V_66 * V_67 , const struct V_68 * V_26 ,
int V_24 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
static unsigned int V_44 = 0 ;
F_6 ( L_7 , ( int ) type , V_14 ) ;
while ( ! ( V_2 = F_16 ( sizeof( struct V_15 ) , V_28 ) ) )
F_7 () ;
V_16 = (struct V_15 * ) F_17 ( V_2 , sizeof( struct V_15 ) ) ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> type = type ;
* (struct V_13 * * ) & V_16 -> V_14 = V_14 ;
* (struct V_13 * * ) & V_16 -> V_52 = V_52 ;
V_16 -> V_24 = V_24 ;
if ( V_26 )
V_16 -> V_26 = * V_26 ;
if ( V_14 )
V_16 -> V_69 = V_14 -> V_69 ;
if ( V_67 )
V_16 -> V_67 = * V_67 ;
if ( V_14 )
V_16 -> V_36 = V_14 -> V_36 ;
if ( V_48 )
V_16 -> V_48 = * V_48 ;
if ( V_14 ) {
if ( type == V_70 && F_15 ( V_71 , & V_14 -> V_18 ) )
V_16 -> V_44 = ++ V_44 ;
}
F_1 ( V_2 ) ;
if ( V_14 )
F_27 ( V_50 , & V_14 -> V_18 ) ;
}
void F_23 ( struct V_13 * V_14 , enum V_64 type ,
struct V_13 * V_52 , const struct V_65 * V_48 ,
const struct V_66 * V_67 )
{
F_30 ( V_14 , type , V_52 , V_48 , V_67 , V_14 ? & V_14 -> V_26 : NULL , 0 ) ;
}
static void F_31 ( struct V_13 * V_14 )
{
if ( F_12 ( V_14 ) -> V_72 == V_73 &&
! F_15 ( V_74 , & V_14 -> V_18 ) ) {
F_27 ( V_17 , & V_14 -> V_18 ) ;
F_20 ( V_50 , & V_14 -> V_18 ) ;
F_28 ( V_14 , - V_75 ) ;
}
}
static void F_32 ( struct V_13 * V_14 )
{
struct V_76 * V_77 ;
struct V_30 * V_78 ;
int V_79 ;
F_6 ( L_8 ) ;
V_6 = NULL ;
if ( F_33 ( & F_12 ( V_14 ) -> V_11 ) )
F_34 ( L_9 ) ;
F_35 ( & F_12 ( V_14 ) -> V_11 ) ;
F_36 ( & V_80 ) ;
for ( V_79 = 0 ; V_79 < V_81 ; ++ V_79 ) {
struct V_82 * V_83 = & V_84 [ V_79 ] ;
F_37 (s, node, head) {
V_14 = F_38 ( V_78 ) ;
F_31 ( V_14 ) ;
}
}
F_39 ( & V_80 ) ;
}
int F_40 ( struct V_13 * V_14 )
{
if ( V_6 )
return - V_85 ;
F_6 ( L_8 ) ;
V_6 = V_14 ;
V_14 -> V_21 = & V_86 ;
F_41 ( F_12 ( V_14 ) ) ;
F_27 ( V_74 , & V_14 -> V_18 ) ;
F_27 ( V_19 , & V_14 -> V_18 ) ;
#ifdef F_2
F_42 ( & V_5 ) ;
#endif
return 0 ;
}
