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
memcpy ( V_1 -> V_5 -> V_21 ,
V_1 -> V_6 [ 0 ] -> V_21 , V_22 ) ;
V_14 = F_19 ( & V_1 -> V_23 ,
V_1 -> V_5 -> V_21 ,
V_1 -> V_6 [ 1 ] ?
V_1 -> V_6 [ 1 ] -> V_21 :
V_1 -> V_5 -> V_21 ) ;
if ( V_14 )
F_20 ( V_1 -> V_5 ,
L_1 ) ;
if ( V_5 == V_1 -> V_6 [ 0 ] )
F_21 ( V_20 , V_1 -> V_5 ) ;
break;
case V_24 :
if ( V_5 == V_1 -> V_5 )
break;
V_13 = F_22 ( V_1 ) ;
if ( V_1 -> V_5 -> V_25 > V_13 )
F_23 ( V_1 -> V_5 , V_13 ) ;
break;
case V_26 :
if ( V_5 == V_1 -> V_6 [ 0 ] )
V_1 -> V_6 [ 0 ] = NULL ;
if ( V_5 == V_1 -> V_6 [ 1 ] )
V_1 -> V_6 [ 1 ] = NULL ;
break;
case V_27 :
return V_28 ;
}
return V_15 ;
}
static void F_24 ( unsigned long V_29 )
{
struct V_1 * V_1 ;
F_9 () ;
F_7 (hsr_priv, &hsr_list, hsr_list)
F_25 ( V_1 ) ;
F_10 () ;
V_30 . V_31 = V_32 + F_26 ( V_33 ) ;
F_27 ( & V_30 ) ;
}
static struct V_34 * F_28 ( struct V_34 * V_35 )
{
struct V_36 * V_36 ;
struct V_34 * V_37 ;
V_37 = F_29 ( V_35 , V_38 ) ;
if ( F_30 ( ! V_37 ) )
goto V_39;
V_35 = V_37 ;
if ( F_30 ( ! F_31 ( V_35 , V_40 ) ) )
goto V_39;
V_36 = (struct V_36 * ) V_35 -> V_29 ;
V_35 -> V_41 = V_36 -> V_42 ;
F_32 ( V_35 , V_40 ) ;
return V_35 ;
V_39:
F_33 ( V_35 ) ;
return NULL ;
}
static bool F_34 ( struct V_1 * V_1 , struct V_34 * V_35 )
{
struct V_43 * V_44 ;
if ( ! F_35 ( F_36 ( V_35 ) -> V_45 ,
V_1 -> V_46 ) )
return false ;
V_44 = (struct V_43 * ) V_35 -> V_29 ;
if ( F_37 ( V_44 ) != 0x0f )
return false ;
if ( ( V_44 -> V_47 != V_48 ) &&
( V_44 -> V_47 != V_49 ) )
return false ;
if ( V_44 -> V_50 != 12 )
return false ;
return true ;
}
static int F_38 ( struct V_34 * V_35 , struct V_4 * V_5 ,
struct V_51 * V_52 , struct V_4 * V_53 )
{
struct V_1 * V_1 ;
struct V_4 * V_11 ;
struct V_54 * V_55 ;
bool V_56 ;
struct V_34 * V_57 ;
enum V_58 V_59 , V_60 ;
bool V_61 ;
int V_62 ;
V_1 = F_8 ( V_5 ) ;
if ( ! V_1 ) {
F_33 ( V_35 ) ;
V_5 -> V_63 . V_64 ++ ;
return V_65 ;
}
if ( V_5 == V_1 -> V_6 [ 0 ] ) {
V_59 = V_66 ;
V_60 = V_67 ;
} else {
V_59 = V_67 ;
V_60 = V_66 ;
}
V_55 = F_39 ( & V_1 -> V_23 , V_35 ) ;
if ( V_55 ) {
F_33 ( V_35 ) ;
return V_65 ;
}
V_56 = false ;
if ( ( V_35 -> V_68 == V_69 ) ||
( V_35 -> V_68 == V_70 ) ||
( V_35 -> V_68 == V_71 ) )
V_56 = true ;
else if ( F_35 ( F_36 ( V_35 ) -> V_45 ,
V_1 -> V_5 -> V_21 ) ) {
V_35 -> V_68 = V_69 ;
V_56 = true ;
}
F_9 () ;
V_55 = F_39 ( & V_1 -> V_72 , V_35 ) ;
if ( F_34 ( V_1 , V_35 ) ) {
F_32 ( V_35 , sizeof( struct V_43 ) ) ;
V_55 = F_40 ( V_1 , V_55 , V_35 , V_59 ) ;
if ( ! V_55 ) {
F_10 () ;
F_33 ( V_35 ) ;
V_1 -> V_5 -> V_63 . V_73 ++ ;
return V_74 ;
}
F_41 ( V_35 , sizeof( struct V_43 ) ) ;
V_56 = false ;
}
if ( ! V_55 ) {
F_10 () ;
F_33 ( V_35 ) ;
return V_65 ;
}
V_61 = F_42 ( V_55 , V_60 , V_35 ) ;
if ( ! V_61 )
F_43 ( V_55 , V_59 ) ;
if ( ! V_61 && ( V_35 -> V_68 != V_69 ) )
V_11 = F_11 ( V_1 , V_5 ) ;
else
V_11 = NULL ;
if ( F_42 ( V_55 , V_75 , V_35 ) )
V_56 = false ;
F_10 () ;
if ( ! V_56 && ! V_11 ) {
F_33 ( V_35 ) ;
return V_65 ;
}
V_57 = V_35 ;
if ( V_56 && V_11 ) {
V_57 = F_44 ( V_35 , V_38 ) ;
if ( ! V_57 ) {
V_56 = false ;
V_1 -> V_5 -> V_63 . V_73 ++ ;
}
}
if ( V_56 ) {
bool V_76 ;
V_57 = F_28 ( V_57 ) ;
if ( ! V_57 ) {
V_1 -> V_5 -> V_63 . V_73 ++ ;
goto V_77;
}
#if ! F_45 ( V_78 )
memmove ( V_57 -> V_29 - V_40 , V_57 -> V_29 ,
F_46 ( V_57 ) ) ;
V_57 -> V_29 -= V_40 ;
V_57 -> V_79 -= V_40 ;
#endif
V_57 -> V_5 = V_1 -> V_5 ;
F_47 ( V_1 , V_57 ) ;
V_76 = ( V_57 -> V_68 == V_70 ) ;
V_62 = F_48 ( V_57 ) ;
if ( V_62 == V_74 ) {
V_1 -> V_5 -> V_63 . V_73 ++ ;
} else {
V_1 -> V_5 -> V_63 . V_80 ++ ;
V_1 -> V_5 -> V_63 . V_81 += V_35 -> V_82 ;
if ( V_76 )
V_1 -> V_5 -> V_63 . V_83 ++ ;
}
}
V_77:
if ( V_11 ) {
F_41 ( V_35 , V_84 ) ;
V_35 -> V_5 = V_11 ;
F_49 ( V_35 ) ;
}
return V_65 ;
}
static int T_1 F_50 ( void )
{
int V_14 ;
F_51 ( sizeof( struct V_36 ) != V_40 ) ;
F_52 ( & V_85 ) ;
F_53 ( & V_30 ) ;
V_30 . V_86 = F_24 ;
V_30 . V_29 = 0 ;
V_30 . V_31 = V_32 + F_26 ( V_33 ) ;
F_27 ( & V_30 ) ;
F_54 ( & V_87 ) ;
V_14 = F_55 () ;
return V_14 ;
}
static void T_2 F_56 ( void )
{
F_57 ( & V_87 ) ;
F_58 ( & V_30 ) ;
F_59 () ;
F_60 ( & V_85 ) ;
}
