static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 = V_3 * V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ ) {
char * V_8 = F_2 ( 6 , V_9 ) ;
snprintf ( V_8 , 6 , L_1 , V_5 + V_7 ) ;
V_2 [ V_7 ] . V_10 = V_5 + V_7 ;
V_2 [ V_7 ] . V_8 = V_8 ;
}
V_11 [ V_3 ] = V_4 ;
}
static int F_3 ( struct V_12 * V_13 ,
unsigned V_14 , unsigned long * V_15 )
{
return - V_16 ;
}
static int F_4 ( struct V_12 * V_13 ,
unsigned V_14 , unsigned long V_15 )
{
return - V_16 ;
}
static int F_5 ( struct V_12 * V_13 ,
unsigned V_17 , unsigned long * V_15 )
{
struct V_18 * V_19 = F_6 ( V_13 ) ;
enum V_20 V_21 = F_7 ( * V_15 ) ;
void T_1 * V_22 = V_19 -> V_23 [ F_8 ( V_17 ) ] ;
switch ( V_21 ) {
case V_24 :
* V_15 = F_9 ( V_21 ,
! ! F_10 ( V_22 , V_25 , F_11 ( V_17 ) ) ) ;
break;
case V_26 :
* V_15 = F_9 ( V_21 ,
! ! F_10 ( V_22 , V_27 , F_11 ( V_17 ) ) ) ;
break;
case V_28 :
if ( F_10 ( V_22 , V_29 , F_11 ( V_17 ) ) )
* V_15 = F_9 ( V_21 , 1 ) ;
else if ( F_10 ( V_22 , V_30 , F_11 ( V_17 ) ) )
* V_15 = F_9 ( V_21 , 2 ) ;
else
* V_15 = F_9 ( V_21 , 0 ) ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_12 ( struct V_12 * V_13 ,
unsigned V_17 , unsigned long V_15 )
{
enum V_20 V_21 = F_7 ( V_15 ) ;
int V_31 = F_13 ( V_15 ) ;
struct V_18 * V_19 = F_6 ( V_13 ) ;
void T_1 * V_22 = V_19 -> V_23 [ F_8 ( V_17 ) ] ;
T_2 V_32 ;
switch ( V_21 ) {
case V_24 :
V_32 = V_25 ;
break;
case V_26 :
V_32 = V_27 ;
break;
case V_28 :
if ( V_31 == 1 )
V_32 = V_29 ;
else
V_32 = V_30 ;
break;
default:
F_14 ( L_2 ,
F_15 ( V_13 ) , V_21 ) ;
return - V_16 ;
}
F_16 ( V_22 , F_17 ( F_11 ( V_17 ) ) , V_32 ) ;
if ( ! ( F_18 ( V_22 , V_32 ) & F_17 ( F_11 ( V_17 ) ) ) )
return - V_16 ;
return 0 ;
}
static void F_19 ( struct V_12 * V_13 ,
struct V_33 * V_34 , unsigned V_35 )
{
}
static void F_20 ( struct V_12 * V_13 ,
struct V_33 * V_34 , unsigned V_36 )
{
}
static inline int F_21 ( struct V_12 * V_13 ,
int V_37 , int V_38 )
{
struct V_18 * V_19 = F_6 ( V_13 ) ;
int V_39 = F_8 ( V_19 -> V_37 [ V_37 ] . V_17 ) ;
if ( ( V_39 >= V_40 ) || ( ! V_19 -> V_23 [ V_39 ] ) )
return - V_41 ;
F_16 ( V_19 -> V_23 [ V_39 ] , V_38 ,
F_22 ( F_11 ( V_19 -> V_37 [ V_37 ] . V_17 ) ) ) ;
return 0 ;
}
int F_23 ( int V_42 )
{
T_2 V_43 ;
if ( ( V_42 >= V_40 ) || ( ! V_44 . V_23 [ V_42 ] ) )
return - V_45 ;
V_43 = F_18 ( V_44 . V_23 [ V_42 ] , V_46 ) ;
return F_24 ( V_43 ) ;
}
void F_25 ( struct V_47 * V_48 )
{
F_26 ( V_44 . V_49 , V_48 ) ;
}
static int F_27 ( struct V_50 * V_51 )
{
struct V_52 * V_53 ;
int V_11 = 0 ;
int V_54 = 0 ;
F_28 (np, NULL, L_3 ) {
struct V_50 * V_55 = F_29 ( V_53 ) ;
const T_3 * V_3 = F_30 ( V_53 , L_4 , NULL ) ;
struct V_56 V_57 ;
T_2 V_43 ;
int V_58 ;
if ( ! V_55 ) {
F_31 ( & V_51 -> V_59 , L_5 ) ;
continue;
}
if ( ! V_3 || * V_3 >= V_40 )
continue;
if ( F_32 ( V_53 , 0 , & V_57 ) )
continue;
V_44 . V_60 [ * V_3 ] = F_33 ( & V_55 -> V_59 , NULL ) ;
if ( F_34 ( V_44 . V_60 [ * V_3 ] ) ) {
F_31 ( & V_55 -> V_59 , L_6 ) ;
return F_35 ( V_44 . V_60 [ * V_3 ] ) ;
}
V_44 . V_23 [ * V_3 ] =
F_36 ( & V_51 -> V_59 , & V_57 ) ;
if ( ! V_44 . V_23 [ * V_3 ] ) {
F_31 ( & V_51 -> V_59 ,
L_7 ,
* V_3 ) ;
return - V_61 ;
}
V_43 = F_18 ( V_44 . V_23 [ * V_3 ] ,
V_46 ) ;
V_58 = F_24 ( V_43 ) ;
F_1 ( & V_62 [ V_11 ] , * V_3 , V_58 ) ;
V_11 += V_58 ;
F_37 ( V_44 . V_60 [ * V_3 ] ) ;
F_38 ( & V_51 -> V_59 , L_8 ,
V_57 . V_8 , V_58 ) ;
}
F_38 ( & V_51 -> V_59 , L_9 , V_11 ) ;
V_63 . V_8 = F_39 ( & V_51 -> V_59 ) ;
V_63 . V_64 = V_11 ;
V_44 . V_37 = V_65 ;
V_44 . V_66 = F_40 ( V_65 ) ;
V_44 . V_67 = V_68 ;
V_44 . V_69 = F_40 ( V_68 ) ;
V_44 . V_70 = V_71 ;
V_44 . V_72 = F_40 ( V_71 ) ;
V_54 = F_41 ( V_51 , & V_44 ) ;
if ( ! V_54 )
F_42 ( & V_51 -> V_59 , L_10 ) ;
return V_54 ;
}
int T_4 F_43 ( void )
{
return F_44 ( & V_73 ) ;
}
