void F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_2 , & V_2 ) ;
}
void F_3 ( struct V_1 * V_1 )
{
struct V_1 * V_3 ;
F_4 (hsr_priv_it, &hsr_list, hsr_list)
if ( V_3 == V_1 ) {
F_5 ( & V_3 -> V_2 ) ;
return;
}
}
bool F_6 ( struct V_4 * V_5 )
{
struct V_1 * V_3 ;
F_7 (hsr_priv_it, &hsr_list, hsr_list) {
if ( V_5 == V_3 -> V_6 [ 0 ] )
return true ;
if ( V_5 == V_3 -> V_6 [ 1 ] )
return true ;
}
return false ;
}
static struct V_1 * F_8 ( struct V_4 * V_5 )
{
struct V_1 * V_1 ;
F_9 () ;
F_7 (hsr_priv, &hsr_list, hsr_list)
if ( ( V_5 == V_1 -> V_6 [ 0 ] ) ||
( V_5 == V_1 -> V_6 [ 1 ] ) ) {
F_10 () ;
return V_1 ;
}
F_10 () ;
return NULL ;
}
static struct V_4 * F_11 ( struct V_1 * V_1 ,
struct V_4 * V_5 )
{
if ( V_5 == V_1 -> V_6 [ 0 ] )
return V_1 -> V_6 [ 1 ] ;
if ( V_5 == V_1 -> V_6 [ 1 ] )
return V_1 -> V_6 [ 0 ] ;
return NULL ;
}
static int F_12 ( struct V_7 * V_8 , unsigned long V_9 ,
void * V_10 )
{
struct V_4 * V_6 , * V_11 ;
struct V_1 * V_1 ;
int V_12 ;
int V_13 ;
int V_14 ;
struct V_4 * V_5 ;
V_5 = F_13 ( V_10 ) ;
V_1 = F_8 ( V_5 ) ;
if ( V_1 ) {
V_6 = V_5 ;
V_11 = F_11 ( V_1 , V_6 ) ;
} else {
if ( ! F_14 ( V_5 ) )
return V_15 ;
V_1 = F_15 ( V_5 ) ;
V_6 = V_1 -> V_6 [ 0 ] ;
V_11 = V_1 -> V_6 [ 1 ] ;
}
switch ( V_9 ) {
case V_16 :
case V_17 :
case V_18 :
V_12 = V_1 -> V_5 -> V_19 ;
F_16 ( V_1 -> V_5 , V_6 , V_11 ) ;
F_17 ( V_1 -> V_5 , V_6 , V_11 ) ;
F_18 ( V_1 -> V_5 , V_12 ) ;
break;
case V_20 :
if ( V_5 == V_1 -> V_5 )
break;
if ( V_5 == V_1 -> V_6 [ 0 ] )
F_19 ( V_1 -> V_5 -> V_21 ,
V_1 -> V_6 [ 0 ] -> V_21 ) ;
V_14 = F_20 ( & V_1 -> V_22 ,
V_1 -> V_5 -> V_21 ,
V_1 -> V_6 [ 1 ] ?
V_1 -> V_6 [ 1 ] -> V_21 :
V_1 -> V_5 -> V_21 ) ;
if ( V_14 )
F_21 ( V_1 -> V_5 ,
L_1 ) ;
if ( V_5 == V_1 -> V_6 [ 0 ] )
F_22 ( V_20 , V_1 -> V_5 ) ;
break;
case V_23 :
if ( V_5 == V_1 -> V_5 )
break;
V_13 = F_23 ( V_1 ) ;
if ( V_1 -> V_5 -> V_24 > V_13 )
F_24 ( V_1 -> V_5 , V_13 ) ;
break;
case V_25 :
if ( V_5 == V_1 -> V_6 [ 0 ] )
V_1 -> V_6 [ 0 ] = NULL ;
if ( V_5 == V_1 -> V_6 [ 1 ] )
V_1 -> V_6 [ 1 ] = NULL ;
break;
case V_26 :
return V_27 ;
}
return V_15 ;
}
static void F_25 ( unsigned long V_28 )
{
struct V_1 * V_1 ;
F_9 () ;
F_7 (hsr_priv, &hsr_list, hsr_list)
F_26 ( V_1 ) ;
F_10 () ;
V_29 . V_30 = V_31 + F_27 ( V_32 ) ;
F_28 ( & V_29 ) ;
}
static struct V_33 * F_29 ( struct V_33 * V_34 )
{
struct V_35 * V_35 ;
struct V_33 * V_36 ;
V_36 = F_30 ( V_34 , V_37 ) ;
if ( F_31 ( ! V_36 ) )
goto V_38;
V_34 = V_36 ;
if ( F_31 ( ! F_32 ( V_34 , V_39 ) ) )
goto V_38;
V_35 = (struct V_35 * ) V_34 -> V_28 ;
V_34 -> V_40 = V_35 -> V_41 ;
F_33 ( V_34 , V_39 ) ;
return V_34 ;
V_38:
F_34 ( V_34 ) ;
return NULL ;
}
static bool F_35 ( struct V_1 * V_1 , struct V_33 * V_34 )
{
struct V_42 * V_43 ;
if ( ! F_36 ( F_37 ( V_34 ) -> V_44 ,
V_1 -> V_45 ) )
return false ;
V_43 = (struct V_42 * ) V_34 -> V_28 ;
if ( F_38 ( V_43 ) != 0x0f )
return false ;
if ( ( V_43 -> V_46 != V_47 ) &&
( V_43 -> V_46 != V_48 ) )
return false ;
if ( V_43 -> V_49 != 12 )
return false ;
return true ;
}
static int F_39 ( struct V_33 * V_34 , struct V_4 * V_5 ,
struct V_50 * V_51 , struct V_4 * V_52 )
{
struct V_1 * V_1 ;
struct V_4 * V_11 ;
struct V_53 * V_54 ;
bool V_55 ;
struct V_33 * V_56 ;
enum V_57 V_58 , V_59 ;
bool V_60 ;
int V_61 ;
V_1 = F_8 ( V_5 ) ;
if ( ! V_1 ) {
F_34 ( V_34 ) ;
V_5 -> V_62 . V_63 ++ ;
return V_64 ;
}
if ( V_5 == V_1 -> V_6 [ 0 ] ) {
V_58 = V_65 ;
V_59 = V_66 ;
} else {
V_58 = V_66 ;
V_59 = V_65 ;
}
V_54 = F_40 ( & V_1 -> V_22 , V_34 ) ;
if ( V_54 ) {
F_34 ( V_34 ) ;
return V_64 ;
}
V_55 = false ;
if ( ( V_34 -> V_67 == V_68 ) ||
( V_34 -> V_67 == V_69 ) ||
( V_34 -> V_67 == V_70 ) )
V_55 = true ;
else if ( F_36 ( F_37 ( V_34 ) -> V_44 ,
V_1 -> V_5 -> V_21 ) ) {
V_34 -> V_67 = V_68 ;
V_55 = true ;
}
F_9 () ;
V_54 = F_40 ( & V_1 -> V_71 , V_34 ) ;
if ( F_35 ( V_1 , V_34 ) ) {
F_33 ( V_34 , sizeof( struct V_42 ) ) ;
V_54 = F_41 ( V_1 , V_54 , V_34 , V_58 ) ;
if ( ! V_54 ) {
F_10 () ;
F_34 ( V_34 ) ;
V_1 -> V_5 -> V_62 . V_72 ++ ;
return V_73 ;
}
F_42 ( V_34 , sizeof( struct V_42 ) ) ;
V_55 = false ;
}
if ( ! V_54 ) {
F_10 () ;
F_34 ( V_34 ) ;
return V_64 ;
}
V_60 = F_43 ( V_54 , V_59 , V_34 ) ;
if ( ! V_60 )
F_44 ( V_54 , V_58 ) ;
if ( ! V_60 && ( V_34 -> V_67 != V_68 ) )
V_11 = F_11 ( V_1 , V_5 ) ;
else
V_11 = NULL ;
if ( F_43 ( V_54 , V_74 , V_34 ) )
V_55 = false ;
F_10 () ;
if ( ! V_55 && ! V_11 ) {
F_34 ( V_34 ) ;
return V_64 ;
}
V_56 = V_34 ;
if ( V_55 && V_11 ) {
V_56 = F_45 ( V_34 , V_37 ) ;
if ( ! V_56 ) {
V_55 = false ;
V_1 -> V_5 -> V_62 . V_72 ++ ;
}
}
if ( V_55 ) {
bool V_75 ;
V_56 = F_29 ( V_56 ) ;
if ( ! V_56 ) {
V_1 -> V_5 -> V_62 . V_72 ++ ;
goto V_76;
}
#if ! F_46 ( V_77 )
memmove ( V_56 -> V_28 - V_39 , V_56 -> V_28 ,
F_47 ( V_56 ) ) ;
V_56 -> V_28 -= V_39 ;
V_56 -> V_78 -= V_39 ;
#endif
V_56 -> V_5 = V_1 -> V_5 ;
F_48 ( V_1 , V_56 ) ;
V_75 = ( V_56 -> V_67 == V_69 ) ;
V_61 = F_49 ( V_56 ) ;
if ( V_61 == V_73 ) {
V_1 -> V_5 -> V_62 . V_72 ++ ;
} else {
V_1 -> V_5 -> V_62 . V_79 ++ ;
V_1 -> V_5 -> V_62 . V_80 += V_34 -> V_81 ;
if ( V_75 )
V_1 -> V_5 -> V_62 . V_82 ++ ;
}
}
V_76:
if ( V_11 ) {
F_42 ( V_34 , V_83 ) ;
V_34 -> V_5 = V_11 ;
F_50 ( V_34 ) ;
}
return V_64 ;
}
static int T_1 F_51 ( void )
{
int V_14 ;
F_52 ( sizeof( struct V_35 ) != V_39 ) ;
F_53 ( & V_84 ) ;
F_54 ( & V_29 ) ;
V_29 . V_85 = F_25 ;
V_29 . V_28 = 0 ;
V_29 . V_30 = V_31 + F_27 ( V_32 ) ;
F_28 ( & V_29 ) ;
F_55 ( & V_86 ) ;
V_14 = F_56 () ;
return V_14 ;
}
static void T_2 F_57 ( void )
{
F_58 ( & V_86 ) ;
F_59 ( & V_29 ) ;
F_60 () ;
F_61 ( & V_84 ) ;
}
