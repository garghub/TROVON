int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
return 0 ;
F_2 ( V_4 ) ;
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , unsigned long V_6 )
{
struct V_3 * V_4 ;
int V_7 , V_8 ;
V_4 = F_6 ( sizeof( struct V_3 ) , V_9 ) ;
if ( V_4 == NULL ) {
return - V_10 ;
}
V_2 -> V_5 = ( void * ) V_4 ;
if ( F_7 ( V_2 ) ) {
V_6 |= V_11 ;
} else if ( F_8 ( V_2 ) ) {
V_6 |= V_12 ;
} else {
V_6 |= V_13 ;
}
V_7 = F_9 ( V_4 , V_2 , V_2 -> V_14 , V_6 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_14 -> V_2 , L_1 ) ;
goto V_15;
}
V_8 = F_11 ( V_4 ) ;
if ( V_8 )
F_12 ( & V_2 -> V_14 -> V_2 , L_2 ) ;
V_7 = F_13 ( V_4 ) ;
if ( V_7 )
F_10 ( & V_2 -> V_14 -> V_2 , L_3 ) ;
V_15:
if ( V_7 )
F_1 ( V_2 ) ;
return V_7 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_16 * * V_17 ,
struct V_16 * V_18 ,
T_1 * V_19 )
{
F_15 ( & V_2 -> V_20 ) ;
if ( * V_19 == 1 ) {
if ( ! * V_17 )
* V_17 = V_18 ;
} else if ( * V_19 == 0 ) {
if ( * V_17 == V_18 )
* V_17 = NULL ;
}
* V_19 = * V_17 == V_18 ? 1 : 0 ;
F_16 ( & V_2 -> V_20 ) ;
}
int F_17 ( struct V_1 * V_2 , void * V_21 , struct V_16 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_23 * V_24 ;
struct V_25 * V_26 = & V_4 -> V_27 ;
T_1 * V_28 ;
T_1 V_19 ;
struct V_29 * V_30 ;
int V_31 , V_32 ;
V_24 = V_21 ;
V_28 = ( T_1 * ) ( ( unsigned long ) V_24 -> V_19 ) ;
if ( F_18 ( & V_19 , V_28 , sizeof( V_19 ) ) )
return - V_33 ;
switch ( V_24 -> V_34 ) {
case V_35 :
V_19 = V_2 -> V_36 ;
break;
case V_37 :
V_19 = V_4 -> V_38 ;
break;
case V_39 :
V_19 = V_4 -> V_40 ;
break;
case V_41 :
if ( ( V_4 -> V_42 >= V_43 ) && ( V_4 -> V_42 <= V_44 ) )
V_19 = false ;
else
V_19 = V_4 -> V_45 ;
break;
case V_46 :
for ( V_31 = 0 , V_32 = 0 ; V_31 < V_4 -> V_47 ; V_31 ++ ) {
V_30 = (struct V_29 * ) V_26 -> V_48 [ V_31 ] ;
if ( V_30 && V_30 -> V_49 . V_50 == V_19 ) {
struct V_51 * V_51 = F_19 ( V_30 ) ;
V_19 = V_51 -> V_52 ;
V_32 = 1 ;
break;
}
}
if ( ! V_32 ) {
F_20 ( L_4 , V_19 ) ;
return - V_53 ;
}
break;
case V_54 :
V_19 = V_4 -> V_45 ;
break;
case V_55 :
if ( V_4 -> V_42 >= V_56 )
V_19 = V_4 -> V_57 . V_58 . V_59 ;
else if ( V_4 -> V_42 >= V_43 )
V_19 = V_4 -> V_57 . V_60 . V_59 ;
else if ( V_4 -> V_42 >= V_61 )
V_19 = V_4 -> V_57 . V_62 . V_59 ;
else if ( V_4 -> V_42 >= V_63 )
V_19 = V_4 -> V_57 . V_64 . V_59 ;
else {
F_20 ( L_5 ) ;
return - V_53 ;
}
break;
case V_65 :
if ( V_19 >= 2 ) {
F_20 ( L_6 , V_19 ) ;
return - V_53 ;
}
F_14 ( V_2 , & V_4 -> V_66 , V_22 , & V_19 ) ;
break;
case V_67 :
if ( V_19 >= 2 ) {
F_20 ( L_7 , V_19 ) ;
return - V_53 ;
}
F_14 ( V_2 , & V_4 -> V_68 , V_22 , & V_19 ) ;
break;
case V_69 :
V_19 = V_4 -> clock . V_70 . V_71 * 10 ;
break;
case V_72 :
if ( V_4 -> V_42 >= V_56 )
V_19 = V_4 -> V_57 . V_58 . V_73 *
V_4 -> V_57 . V_58 . V_74 ;
else if ( V_4 -> V_42 >= V_43 )
V_19 = V_4 -> V_57 . V_60 . V_75 ;
else if ( V_4 -> V_42 >= V_61 )
V_19 = V_4 -> V_57 . V_62 . V_75 ;
else if ( V_4 -> V_42 >= V_63 )
V_19 = V_4 -> V_57 . V_64 . V_75 ;
else {
return - V_53 ;
}
break;
case V_76 :
if ( V_4 -> V_42 >= V_56 )
V_19 = V_4 -> V_57 . V_58 . V_77 ;
else if ( V_4 -> V_42 >= V_43 )
V_19 = V_4 -> V_57 . V_60 . V_77 ;
else if ( V_4 -> V_42 >= V_61 )
V_19 = V_4 -> V_57 . V_62 . V_77 ;
else if ( V_4 -> V_42 >= V_63 )
V_19 = V_4 -> V_57 . V_64 . V_77 ;
else {
return - V_53 ;
}
break;
case V_78 :
V_19 = 1 ;
break;
default:
F_20 ( L_8 , V_24 -> V_34 ) ;
return - V_53 ;
}
if ( F_21 ( V_28 , & V_19 , sizeof( T_1 ) ) ) {
F_22 ( L_9 ) ;
return - V_33 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
F_25 () ;
}
int F_26 ( struct V_1 * V_2 , struct V_16 * V_79 )
{
return 0 ;
}
void F_27 ( struct V_1 * V_2 ,
struct V_16 * V_79 )
{
}
void F_28 ( struct V_1 * V_2 ,
struct V_16 * V_79 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_66 == V_79 )
V_4 -> V_66 = NULL ;
if ( V_4 -> V_68 == V_79 )
V_4 -> V_68 = NULL ;
}
T_2 F_29 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_30 < 0 || V_30 >= V_4 -> V_47 ) {
F_22 ( L_10 , V_30 ) ;
return - V_53 ;
}
return F_30 ( V_4 , V_30 ) ;
}
int F_31 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_30 < 0 || V_30 >= V_4 -> V_47 ) {
F_22 ( L_10 , V_30 ) ;
return - V_53 ;
}
V_4 -> V_80 . V_81 [ V_30 ] = true ;
return F_32 ( V_4 ) ;
}
void F_33 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_30 < 0 || V_30 >= V_4 -> V_47 ) {
F_22 ( L_10 , V_30 ) ;
return;
}
V_4 -> V_80 . V_81 [ V_30 ] = false ;
F_32 ( V_4 ) ;
}
int F_34 ( struct V_1 * V_2 , int V_30 ,
int * V_82 ,
struct V_83 * V_84 ,
unsigned V_6 )
{
struct V_29 * V_85 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_30 < 0 || V_30 >= V_2 -> V_86 ) {
F_22 ( L_10 , V_30 ) ;
return - V_53 ;
}
V_85 = & V_4 -> V_27 . V_48 [ V_30 ] -> V_49 ;
return F_35 ( V_2 , V_30 , V_82 ,
V_84 , V_6 ,
V_85 ) ;
}
int F_36 ( struct V_1 * V_2 , void * V_21 ,
struct V_16 * V_79 )
{
return - V_53 ;
}
