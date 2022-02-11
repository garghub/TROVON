static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_3 ) {
F_2 ( L_1 ) ;
F_3 ( V_2 ) ;
return;
}
F_4 ( V_3 , V_2 -> V_4 ) ;
F_5 ( & F_6 ( V_3 ) -> V_5 , V_2 ) ;
F_6 ( V_3 ) -> F_7 ( F_6 ( V_3 ) ) ;
}
static void F_8 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_2 ;
if ( F_9 ( V_10 , & V_7 -> V_11 ) ||
! F_9 ( V_12 , & V_7 -> V_11 ) )
return;
V_9 -> type = V_13 ;
if ( ! V_7 -> V_14 -> V_15 -> V_16 )
V_9 -> V_17 = - V_18 ;
else {
V_9 -> V_17 = V_7 -> V_14 -> V_15 -> V_16 ( V_7 , & V_9 -> V_19 ,
V_9 -> V_17 ) ;
if ( ! V_9 -> V_17 )
V_9 -> type = V_20 ;
}
while ( ! ( V_2 = F_10 ( sizeof( struct V_8 ) , V_21 ) ) )
F_11 () ;
* (struct V_8 * ) F_12 ( V_2 , sizeof( struct V_8 ) ) = * V_9 ;
F_1 ( V_2 ) ;
}
static int F_13 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_6 * V_22 ;
struct V_23 * V_24 ;
V_9 = (struct V_8 * ) V_2 -> V_25 ;
F_14 ( F_15 ( V_2 -> V_4 , & F_6 ( V_7 ) -> V_26 ) ) ;
V_7 = * (struct V_6 * * ) & V_9 -> V_7 ;
F_2 ( L_2 , ( int ) V_9 -> type , ( unsigned long ) V_7 ) ;
V_24 = F_6 ( V_7 ) ;
switch ( V_9 -> type ) {
case V_20 :
V_24 -> V_27 = - V_9 -> V_17 ;
F_16 ( V_28 , & V_7 -> V_11 ) ;
if ( ! * V_7 -> V_29 . V_30 . V_31 && ! * V_7 -> V_29 . V_30 . V_32 ) {
V_7 -> V_29 . V_33 = V_34 ;
memcpy ( V_7 -> V_29 . V_30 . V_31 ,
V_9 -> V_29 . V_30 . V_31 , V_35 ) ;
memcpy ( V_7 -> V_29 . V_30 . V_32 ,
V_9 -> V_29 . V_30 . V_32 , V_36 + 1 ) ;
}
V_22 = V_7 -> V_37 ? V_7 -> V_37 : V_7 ;
if ( V_22 -> V_38 || V_22 -> V_39 )
break;
V_22 -> V_40 = V_9 -> V_41 . V_42 . V_40 ;
V_22 -> V_38 = V_9 -> V_41 . V_42 . V_38 ;
V_22 -> V_39 = V_9 -> V_41 . V_42 . V_39 ;
if ( V_22 -> V_38 || V_22 -> V_39 )
V_22 -> V_19 = V_9 -> V_19 ;
break;
case V_13 :
F_16 ( V_43 , & V_7 -> V_11 ) ;
F_16 ( V_12 , & V_7 -> V_11 ) ;
V_24 -> V_27 = - V_9 -> V_17 ;
F_16 ( V_28 , & V_7 -> V_11 ) ;
break;
case V_44 :
V_7 = * (struct V_6 * * ) & V_9 -> V_45 ;
V_24 = F_6 ( V_7 ) ;
F_2 ( L_3 ) ;
F_17 ( V_24 ) ;
if ( F_18 ( V_24 ) ) {
F_19 ( NULL , V_46 , V_7 , NULL , NULL ) ;
F_20 ( V_2 ) ;
goto V_47;
}
V_24 -> V_48 ++ ;
F_5 ( & V_24 -> V_5 , V_2 ) ;
F_2 ( L_4 , F_21 ( V_24 ) ) ;
V_24 -> V_49 ( V_24 ) ;
V_47:
F_22 ( V_24 ) ;
return 0 ;
case V_50 :
F_23 ( V_10 , & V_7 -> V_11 ) ;
F_24 ( V_7 , V_9 -> V_17 ) ;
goto V_51;
case V_52 :
F_8 ( V_7 , V_9 ) ;
break;
case V_53 :
case V_54 :
V_24 -> V_55 = - V_9 -> V_17 ;
F_16 ( V_28 , & V_7 -> V_11 ) ;
break;
default:
F_25 ( L_5 , ( int ) V_9 -> type ) ;
return - V_56 ;
}
V_24 -> V_49 ( V_24 ) ;
V_51:
F_20 ( V_2 ) ;
return 0 ;
}
void F_26 ( struct V_6 * V_7 , enum V_57 type ,
struct V_6 * V_45 , const struct V_58 * V_41 ,
const struct V_59 * V_60 , const struct V_61 * V_19 ,
int V_17 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
static unsigned int V_37 = 0 ;
F_2 ( L_6 , ( int ) type , V_7 ) ;
while ( ! ( V_2 = F_10 ( sizeof( struct V_8 ) , V_21 ) ) )
F_11 () ;
V_9 = F_27 ( V_2 , sizeof( struct V_8 ) ) ;
V_9 -> type = type ;
* (struct V_6 * * ) & V_9 -> V_7 = V_7 ;
* (struct V_6 * * ) & V_9 -> V_45 = V_45 ;
V_9 -> V_17 = V_17 ;
if ( V_19 )
V_9 -> V_19 = * V_19 ;
if ( V_7 )
V_9 -> V_62 = V_7 -> V_62 ;
if ( V_60 )
V_9 -> V_60 = * V_60 ;
if ( V_7 )
V_9 -> V_29 = V_7 -> V_29 ;
if ( V_41 )
V_9 -> V_41 = * V_41 ;
if ( V_7 ) {
if ( type == V_63 && F_9 ( V_64 , & V_7 -> V_11 ) )
V_9 -> V_37 = ++ V_37 ;
}
F_1 ( V_2 ) ;
if ( V_7 )
F_23 ( V_43 , & V_7 -> V_11 ) ;
}
void F_19 ( struct V_6 * V_7 , enum V_57 type ,
struct V_6 * V_45 , const struct V_58 * V_41 ,
const struct V_59 * V_60 )
{
F_26 ( V_7 , type , V_45 , V_41 , V_60 , V_7 ? & V_7 -> V_19 : NULL , 0 ) ;
}
static void F_28 ( struct V_6 * V_7 )
{
if ( F_6 ( V_7 ) -> V_65 == V_66 &&
! F_9 ( V_67 , & V_7 -> V_11 ) ) {
F_23 ( V_10 , & V_7 -> V_11 ) ;
F_16 ( V_43 , & V_7 -> V_11 ) ;
F_24 ( V_7 , - V_68 ) ;
}
}
static void F_29 ( struct V_6 * V_7 )
{
struct V_23 * V_69 ;
int V_70 ;
F_2 ( L_7 ) ;
V_3 = NULL ;
if ( F_30 ( & F_6 ( V_7 ) -> V_5 ) )
F_31 ( L_8 ) ;
F_32 ( & F_6 ( V_7 ) -> V_5 ) ;
F_33 ( & V_71 ) ;
for ( V_70 = 0 ; V_70 < V_72 ; ++ V_70 ) {
struct V_73 * V_74 = & V_75 [ V_70 ] ;
F_34 (s, head) {
V_7 = F_35 ( V_69 ) ;
F_28 ( V_7 ) ;
}
}
F_36 ( & V_71 ) ;
}
int F_37 ( struct V_6 * V_7 )
{
if ( V_3 )
return - V_76 ;
F_2 ( L_7 ) ;
V_3 = V_7 ;
V_7 -> V_14 = & V_77 ;
F_38 ( F_6 ( V_7 ) ) ;
F_23 ( V_67 , & V_7 -> V_11 ) ;
F_23 ( V_12 , & V_7 -> V_11 ) ;
return 0 ;
}
