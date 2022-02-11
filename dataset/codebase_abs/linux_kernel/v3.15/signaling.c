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
F_12 ( V_6 ) -> F_13 ( F_12 ( V_6 ) ) ;
}
static void F_14 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_1 * V_2 ;
if ( F_15 ( V_16 , & V_13 -> V_17 ) ||
! F_15 ( V_18 , & V_13 -> V_17 ) )
return;
V_15 -> type = V_19 ;
if ( ! V_13 -> V_20 -> V_21 -> V_22 )
V_15 -> V_23 = - V_24 ;
else {
V_15 -> V_23 = V_13 -> V_20 -> V_21 -> V_22 ( V_13 , & V_15 -> V_25 ,
V_15 -> V_23 ) ;
if ( ! V_15 -> V_23 )
V_15 -> type = V_26 ;
}
while ( ! ( V_2 = F_16 ( sizeof( struct V_14 ) , V_27 ) ) )
F_7 () ;
* (struct V_14 * ) F_17 ( V_2 , sizeof( struct V_14 ) ) = * V_15 ;
F_1 ( V_2 ) ;
}
static int F_18 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_12 * V_28 ;
struct V_29 * V_30 ;
V_15 = (struct V_14 * ) V_2 -> V_31 ;
F_19 ( V_2 -> V_10 , & F_12 ( V_13 ) -> V_32 ) ;
V_13 = * (struct V_12 * * ) & V_15 -> V_13 ;
F_6 ( L_3 , ( int ) V_15 -> type , ( unsigned long ) V_13 ) ;
V_30 = F_12 ( V_13 ) ;
switch ( V_15 -> type ) {
case V_26 :
V_30 -> V_33 = - V_15 -> V_23 ;
F_20 ( V_34 , & V_13 -> V_17 ) ;
if ( ! * V_13 -> V_35 . V_36 . V_37 && ! * V_13 -> V_35 . V_36 . V_38 ) {
V_13 -> V_35 . V_39 = V_40 ;
memcpy ( V_13 -> V_35 . V_36 . V_37 ,
V_15 -> V_35 . V_36 . V_37 , V_41 ) ;
memcpy ( V_13 -> V_35 . V_36 . V_38 ,
V_15 -> V_35 . V_36 . V_38 , V_42 + 1 ) ;
}
V_28 = V_13 -> V_43 ? V_13 -> V_43 : V_13 ;
if ( V_28 -> V_44 || V_28 -> V_45 )
break;
V_28 -> V_46 = V_15 -> V_47 . V_48 . V_46 ;
V_28 -> V_44 = V_15 -> V_47 . V_48 . V_44 ;
V_28 -> V_45 = V_15 -> V_47 . V_48 . V_45 ;
if ( V_28 -> V_44 || V_28 -> V_45 )
V_28 -> V_25 = V_15 -> V_25 ;
break;
case V_19 :
F_20 ( V_49 , & V_13 -> V_17 ) ;
F_20 ( V_18 , & V_13 -> V_17 ) ;
V_30 -> V_33 = - V_15 -> V_23 ;
F_20 ( V_34 , & V_13 -> V_17 ) ;
break;
case V_50 :
V_13 = * (struct V_12 * * ) & V_15 -> V_51 ;
V_30 = F_12 ( V_13 ) ;
F_6 ( L_4 ) ;
F_21 ( V_30 ) ;
if ( F_22 ( V_30 ) ) {
F_23 ( NULL , V_52 , V_13 , NULL , NULL ) ;
F_24 ( V_2 ) ;
goto V_53;
}
V_30 -> V_54 ++ ;
F_11 ( & V_30 -> V_11 , V_2 ) ;
F_6 ( L_5 , F_25 ( V_30 ) ) ;
V_30 -> V_55 ( V_30 ) ;
V_53:
F_26 ( V_30 ) ;
return 0 ;
case V_56 :
F_27 ( V_16 , & V_13 -> V_17 ) ;
F_28 ( V_13 , V_15 -> V_23 ) ;
goto V_57;
case V_58 :
F_14 ( V_13 , V_15 ) ;
break;
case V_59 :
case V_60 :
V_30 -> V_61 = V_15 -> V_23 ;
F_20 ( V_34 , & V_13 -> V_17 ) ;
break;
default:
F_29 ( L_6 , ( int ) V_15 -> type ) ;
return - V_62 ;
}
V_30 -> V_55 ( V_30 ) ;
V_57:
F_24 ( V_2 ) ;
return 0 ;
}
void F_30 ( struct V_12 * V_13 , enum V_63 type ,
struct V_12 * V_51 , const struct V_64 * V_47 ,
const struct V_65 * V_66 , const struct V_67 * V_25 ,
int V_23 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
static unsigned int V_43 = 0 ;
F_6 ( L_7 , ( int ) type , V_13 ) ;
while ( ! ( V_2 = F_16 ( sizeof( struct V_14 ) , V_27 ) ) )
F_7 () ;
V_15 = (struct V_14 * ) F_17 ( V_2 , sizeof( struct V_14 ) ) ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> type = type ;
* (struct V_12 * * ) & V_15 -> V_13 = V_13 ;
* (struct V_12 * * ) & V_15 -> V_51 = V_51 ;
V_15 -> V_23 = V_23 ;
if ( V_25 )
V_15 -> V_25 = * V_25 ;
if ( V_13 )
V_15 -> V_68 = V_13 -> V_68 ;
if ( V_66 )
V_15 -> V_66 = * V_66 ;
if ( V_13 )
V_15 -> V_35 = V_13 -> V_35 ;
if ( V_47 )
V_15 -> V_47 = * V_47 ;
if ( V_13 ) {
if ( type == V_69 && F_15 ( V_70 , & V_13 -> V_17 ) )
V_15 -> V_43 = ++ V_43 ;
}
F_1 ( V_2 ) ;
if ( V_13 )
F_27 ( V_49 , & V_13 -> V_17 ) ;
}
void F_23 ( struct V_12 * V_13 , enum V_63 type ,
struct V_12 * V_51 , const struct V_64 * V_47 ,
const struct V_65 * V_66 )
{
F_30 ( V_13 , type , V_51 , V_47 , V_66 , V_13 ? & V_13 -> V_25 : NULL , 0 ) ;
}
static void F_31 ( struct V_12 * V_13 )
{
if ( F_12 ( V_13 ) -> V_71 == V_72 &&
! F_15 ( V_73 , & V_13 -> V_17 ) ) {
F_27 ( V_16 , & V_13 -> V_17 ) ;
F_20 ( V_49 , & V_13 -> V_17 ) ;
F_28 ( V_13 , - V_74 ) ;
}
}
static void F_32 ( struct V_12 * V_13 )
{
struct V_29 * V_75 ;
int V_76 ;
F_6 ( L_8 ) ;
V_6 = NULL ;
if ( F_33 ( & F_12 ( V_13 ) -> V_11 ) )
F_34 ( L_9 ) ;
F_35 ( & F_12 ( V_13 ) -> V_11 ) ;
F_36 ( & V_77 ) ;
for ( V_76 = 0 ; V_76 < V_78 ; ++ V_76 ) {
struct V_79 * V_80 = & V_81 [ V_76 ] ;
F_37 (s, head) {
V_13 = F_38 ( V_75 ) ;
F_31 ( V_13 ) ;
}
}
F_39 ( & V_77 ) ;
}
int F_40 ( struct V_12 * V_13 )
{
if ( V_6 )
return - V_82 ;
F_6 ( L_8 ) ;
V_6 = V_13 ;
V_13 -> V_20 = & V_83 ;
F_41 ( F_12 ( V_13 ) ) ;
F_27 ( V_73 , & V_13 -> V_17 ) ;
F_27 ( V_18 , & V_13 -> V_17 ) ;
#ifdef F_2
F_42 ( & V_5 ) ;
#endif
return 0 ;
}
