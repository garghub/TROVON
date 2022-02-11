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
unsigned int
F_18 ( struct V_7 * V_8 , void * V_24 )
{
const struct V_3 * V_4 = V_24 , * V_45 = V_4 ;
const struct V_46 * V_46 = F_4 ( V_8 ) ;
const struct V_16 * V_17 ;
const struct V_19 * V_20 , * V_47 ;
struct V_21 V_22 ;
unsigned int V_48 = 0 ;
struct V_49 V_50 [ V_51 ] ;
struct V_52 * V_53 ;
int V_5 ;
unsigned int V_54 = F_19 ( V_46 ) ;
struct V_1 V_2 ;
V_2 . V_9 = false ;
if ( F_10 ( & V_18 ) )
F_20 ( & V_2 , V_8 , & V_22 . V_29 , V_45 ) ;
V_55:
V_5 = 0 ;
V_17 = F_21 ( & V_4 -> V_56 , struct V_16 , V_57 ) ;
V_58:
V_22 . V_29 . V_30 = V_59 ;
F_22 (rule, &chain->rules, list) {
if ( F_16 ( V_17 -> V_60 & V_54 ) )
continue;
V_5 ++ ;
F_23 (expr, last, rule) {
if ( V_20 -> V_61 == & V_62 )
F_11 ( V_20 , & V_22 ) ;
else if ( V_20 -> V_61 != & V_63 ||
! F_14 ( V_20 , & V_22 , V_8 ) )
V_20 -> V_61 -> V_64 ( V_20 , & V_22 , V_8 ) ;
if ( V_22 . V_29 . V_30 != V_59 )
break;
}
switch ( V_22 . V_29 . V_30 ) {
case V_31 :
V_22 . V_29 . V_30 = V_59 ;
continue;
case V_59 :
F_9 ( & V_2 , V_4 , V_17 ,
V_5 , V_65 ) ;
continue;
}
break;
}
switch ( V_22 . V_29 . V_30 & V_66 ) {
case V_67 :
case V_68 :
case V_69 :
case V_70 :
F_9 ( & V_2 , V_4 , V_17 ,
V_5 , V_65 ) ;
return V_22 . V_29 . V_30 ;
}
switch ( V_22 . V_29 . V_30 ) {
case V_71 :
F_24 ( V_48 >= V_51 ) ;
V_50 [ V_48 ] . V_4 = V_4 ;
V_50 [ V_48 ] . V_17 = V_17 ;
V_50 [ V_48 ] . V_5 = V_5 ;
V_48 ++ ;
case V_72 :
F_9 ( & V_2 , V_4 , V_17 ,
V_5 , V_65 ) ;
V_4 = V_22 . V_29 . V_4 ;
goto V_55;
case V_59 :
V_5 ++ ;
case V_73 :
F_9 ( & V_2 , V_4 , V_17 ,
V_5 , V_74 ) ;
break;
default:
F_25 ( 1 ) ;
}
if ( V_48 > 0 ) {
V_48 -- ;
V_4 = V_50 [ V_48 ] . V_4 ;
V_17 = V_50 [ V_48 ] . V_17 ;
V_5 = V_50 [ V_48 ] . V_5 ;
goto V_58;
}
F_9 ( & V_2 , V_45 , NULL , - 1 ,
V_75 ) ;
F_26 () ;
V_53 = F_27 ( F_28 ( F_29 ( V_45 ) -> V_53 ) ) ;
F_30 ( & V_53 -> V_76 ) ;
V_53 -> V_77 ++ ;
V_53 -> V_78 += V_8 -> V_10 -> V_26 ;
F_31 ( & V_53 -> V_76 ) ;
F_32 () ;
return F_29 ( V_45 ) -> V_79 ;
}
int T_3 F_33 ( void )
{
int V_80 , V_81 ;
for ( V_81 = 0 ; V_81 < F_34 ( V_82 ) ; V_81 ++ ) {
V_80 = F_35 ( V_82 [ V_81 ] ) ;
if ( V_80 )
goto V_80;
}
return 0 ;
V_80:
while ( V_81 -- > 0 )
F_36 ( V_82 [ V_81 ] ) ;
return V_80 ;
}
void F_37 ( void )
{
int V_81 ;
V_81 = F_34 ( V_82 ) ;
while ( V_81 -- > 0 )
F_36 ( V_82 [ V_81 ] ) ;
}
