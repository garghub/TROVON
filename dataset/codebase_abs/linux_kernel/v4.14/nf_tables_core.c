static T_1 void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
int V_5 , enum V_6 type )
{
const struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! V_2 -> V_9 || ! V_8 -> V_10 -> V_11 )
return;
V_2 -> V_4 = V_4 ;
V_2 -> type = type ;
F_2 ( V_2 ) ;
F_3 ( F_4 ( V_8 ) , F_5 ( V_8 ) , F_6 ( V_8 ) , V_8 -> V_10 ,
F_7 ( V_8 ) , F_8 ( V_8 ) , & V_12 ,
L_1 ,
V_4 -> V_13 -> V_14 , V_4 -> V_14 , V_15 [ type ] , V_5 ) ;
}
static inline void F_9 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_16 * V_17 ,
int V_5 ,
enum V_6 type )
{
if ( F_10 ( & V_18 ) ) {
V_2 -> V_17 = V_17 ;
F_1 ( V_2 , V_4 , V_5 , type ) ;
}
}
static void F_11 ( const struct V_19 * V_20 ,
struct V_21 * V_22 )
{
const struct V_23 * V_24 = F_12 ( V_20 ) ;
T_2 V_25 = F_13 ( V_24 -> V_26 ) ;
if ( ( V_22 -> V_27 [ V_24 -> V_28 ] & V_25 ) == V_24 -> V_27 )
return;
V_22 -> V_29 . V_30 = V_31 ;
}
static bool F_14 ( const struct V_19 * V_20 ,
struct V_21 * V_22 ,
const struct V_7 * V_8 )
{
const struct V_32 * V_24 = F_12 ( V_20 ) ;
const struct V_33 * V_10 = V_8 -> V_10 ;
T_2 * V_34 = & V_22 -> V_27 [ V_24 -> V_35 ] ;
unsigned char * V_36 ;
if ( V_24 -> V_37 == V_38 )
V_36 = F_15 ( V_10 ) ;
else {
if ( ! V_8 -> V_39 )
return false ;
V_36 = F_15 ( V_10 ) + V_8 -> V_40 . V_41 ;
}
V_36 += V_24 -> V_42 ;
if ( F_16 ( V_36 + V_24 -> V_26 > F_17 ( V_10 ) ) )
return false ;
* V_34 = 0 ;
if ( V_24 -> V_26 == 2 )
* ( V_43 * ) V_34 = * ( V_43 * ) V_36 ;
else if ( V_24 -> V_26 == 4 )
* ( T_2 * ) V_34 = * ( T_2 * ) V_36 ;
else
* ( V_44 * ) V_34 = * ( V_44 * ) V_36 ;
return true ;
}
static T_1 void F_18 ( const struct V_3 * V_4 ,
const struct V_7 * V_8 )
{
struct V_45 * V_46 ;
F_19 () ;
V_46 = F_20 ( F_21 ( F_22 ( V_4 ) -> V_46 ) ) ;
F_23 ( & V_46 -> V_47 ) ;
V_46 -> V_48 ++ ;
V_46 -> V_49 += V_8 -> V_10 -> V_26 ;
F_24 ( & V_46 -> V_47 ) ;
F_25 () ;
}
unsigned int
F_26 ( struct V_7 * V_8 , void * V_24 )
{
const struct V_3 * V_4 = V_24 , * V_50 = V_4 ;
const struct V_51 * V_51 = F_4 ( V_8 ) ;
const struct V_16 * V_17 ;
const struct V_19 * V_20 , * V_52 ;
struct V_21 V_22 ;
unsigned int V_53 = 0 ;
struct V_54 V_55 [ V_56 ] ;
int V_5 ;
unsigned int V_57 = F_27 ( V_51 ) ;
struct V_1 V_2 ;
V_2 . V_9 = false ;
if ( F_10 ( & V_18 ) )
F_28 ( & V_2 , V_8 , & V_22 . V_29 , V_50 ) ;
V_58:
V_5 = 0 ;
V_17 = F_29 ( & V_4 -> V_59 , struct V_16 , V_60 ) ;
V_61:
V_22 . V_29 . V_30 = V_62 ;
F_30 (rule, &chain->rules, list) {
if ( F_16 ( V_17 -> V_63 & V_57 ) )
continue;
V_5 ++ ;
F_31 (expr, last, rule) {
if ( V_20 -> V_64 == & V_65 )
F_11 ( V_20 , & V_22 ) ;
else if ( V_20 -> V_64 != & V_66 ||
! F_14 ( V_20 , & V_22 , V_8 ) )
V_20 -> V_64 -> V_67 ( V_20 , & V_22 , V_8 ) ;
if ( V_22 . V_29 . V_30 != V_62 )
break;
}
switch ( V_22 . V_29 . V_30 ) {
case V_31 :
V_22 . V_29 . V_30 = V_62 ;
continue;
case V_62 :
F_9 ( & V_2 , V_4 , V_17 ,
V_5 , V_68 ) ;
continue;
}
break;
}
switch ( V_22 . V_29 . V_30 & V_69 ) {
case V_70 :
case V_71 :
case V_72 :
case V_73 :
F_9 ( & V_2 , V_4 , V_17 ,
V_5 , V_68 ) ;
return V_22 . V_29 . V_30 ;
}
switch ( V_22 . V_29 . V_30 ) {
case V_74 :
F_32 ( V_53 >= V_56 ) ;
V_55 [ V_53 ] . V_4 = V_4 ;
V_55 [ V_53 ] . V_17 = V_17 ;
V_55 [ V_53 ] . V_5 = V_5 ;
V_53 ++ ;
case V_75 :
F_9 ( & V_2 , V_4 , V_17 ,
V_5 , V_68 ) ;
V_4 = V_22 . V_29 . V_4 ;
goto V_58;
case V_62 :
V_5 ++ ;
case V_76 :
F_9 ( & V_2 , V_4 , V_17 ,
V_5 , V_77 ) ;
break;
default:
F_33 ( 1 ) ;
}
if ( V_53 > 0 ) {
V_53 -- ;
V_4 = V_55 [ V_53 ] . V_4 ;
V_17 = V_55 [ V_53 ] . V_17 ;
V_5 = V_55 [ V_53 ] . V_5 ;
goto V_61;
}
F_9 ( & V_2 , V_50 , NULL , - 1 ,
V_78 ) ;
if ( F_10 ( & V_79 ) )
F_18 ( V_50 , V_8 ) ;
return F_22 ( V_50 ) -> V_80 ;
}
int T_3 F_34 ( void )
{
int V_81 , V_82 ;
for ( V_82 = 0 ; V_82 < F_35 ( V_83 ) ; V_82 ++ ) {
V_81 = F_36 ( V_83 [ V_82 ] ) ;
if ( V_81 )
goto V_81;
}
return 0 ;
V_81:
while ( V_82 -- > 0 )
F_37 ( V_83 [ V_82 ] ) ;
return V_81 ;
}
void F_38 ( void )
{
int V_82 ;
V_82 = F_35 ( V_83 ) ;
while ( V_82 -- > 0 )
F_37 ( V_83 [ V_82 ] ) ;
}
