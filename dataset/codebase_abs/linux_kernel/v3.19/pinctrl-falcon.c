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
unsigned V_14 , unsigned long * V_17 ,
unsigned V_18 )
{
return - V_16 ;
}
static int F_5 ( struct V_12 * V_13 ,
unsigned V_19 , unsigned long * V_15 )
{
struct V_20 * V_21 = F_6 ( V_13 ) ;
enum V_22 V_23 = F_7 ( * V_15 ) ;
void T_1 * V_24 = V_21 -> V_25 [ F_8 ( V_19 ) ] ;
switch ( V_23 ) {
case V_26 :
* V_15 = F_9 ( V_23 ,
! ! F_10 ( V_24 , V_27 , F_11 ( V_19 ) ) ) ;
break;
case V_28 :
* V_15 = F_9 ( V_23 ,
! ! F_10 ( V_24 , V_29 , F_11 ( V_19 ) ) ) ;
break;
case V_30 :
if ( F_10 ( V_24 , V_31 , F_11 ( V_19 ) ) )
* V_15 = F_9 ( V_23 , 1 ) ;
else if ( F_10 ( V_24 , V_32 , F_11 ( V_19 ) ) )
* V_15 = F_9 ( V_23 , 2 ) ;
else
* V_15 = F_9 ( V_23 , 0 ) ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_12 ( struct V_12 * V_13 ,
unsigned V_19 , unsigned long * V_17 ,
unsigned V_18 )
{
enum V_22 V_23 ;
int V_33 ;
struct V_20 * V_21 = F_6 ( V_13 ) ;
void T_1 * V_24 = V_21 -> V_25 [ F_8 ( V_19 ) ] ;
T_2 V_34 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_18 ; V_7 ++ ) {
V_23 = F_7 ( V_17 [ V_7 ] ) ;
V_33 = F_13 ( V_17 [ V_7 ] ) ;
switch ( V_23 ) {
case V_26 :
V_34 = V_27 ;
break;
case V_28 :
V_34 = V_29 ;
break;
case V_30 :
if ( V_33 == 1 )
V_34 = V_31 ;
else
V_34 = V_32 ;
break;
default:
F_14 ( L_2 ,
F_15 ( V_13 ) , V_23 ) ;
return - V_16 ;
}
F_16 ( V_24 , F_17 ( F_11 ( V_19 ) ) , V_34 ) ;
if ( ! ( F_18 ( V_24 , V_34 ) & F_17 ( F_11 ( V_19 ) ) ) )
return - V_16 ;
}
return 0 ;
}
static void F_19 ( struct V_12 * V_13 ,
struct V_35 * V_36 , unsigned V_37 )
{
unsigned long V_15 ;
struct V_38 * V_39 ;
struct V_20 * V_21 = F_6 ( V_13 ) ;
int V_40 = F_8 ( V_37 ) ;
F_20 ( V_36 , L_3 , V_40 ,
F_18 ( V_21 -> V_25 [ V_40 ] , F_21 ( F_11 ( V_37 ) ) ) ) ;
V_15 = F_9 ( V_30 , 0 ) ;
if ( ! F_5 ( V_13 , V_37 , & V_15 ) )
F_20 ( V_36 , L_4 ,
( int ) F_13 ( V_15 ) ) ;
V_15 = F_9 ( V_26 , 0 ) ;
if ( ! F_5 ( V_13 , V_37 , & V_15 ) )
F_20 ( V_36 , L_5 ,
( int ) F_13 ( V_15 ) ) ;
V_15 = F_9 ( V_28 , 0 ) ;
if ( ! F_5 ( V_13 , V_37 , & V_15 ) )
F_20 ( V_36 , L_6 ,
( int ) F_13 ( V_15 ) ) ;
V_39 = F_22 ( V_13 , V_37 ) ;
if ( V_39 ) {
if ( V_39 -> V_41 )
F_20 ( V_36 , L_7 , V_39 -> V_41 ) ;
} else {
F_20 ( V_36 , L_8 ) ;
}
}
static void F_23 ( struct V_12 * V_13 ,
struct V_35 * V_36 , unsigned V_42 )
{
}
static inline int F_24 ( struct V_12 * V_13 ,
int V_43 , int V_44 )
{
struct V_20 * V_21 = F_6 ( V_13 ) ;
int V_40 = F_8 ( V_21 -> V_43 [ V_43 ] . V_19 ) ;
if ( ( V_40 >= V_45 ) || ( ! V_21 -> V_25 [ V_40 ] ) )
return - V_46 ;
F_16 ( V_21 -> V_25 [ V_40 ] , V_44 ,
F_21 ( F_11 ( V_21 -> V_43 [ V_43 ] . V_19 ) ) ) ;
return 0 ;
}
int F_25 ( int V_47 )
{
T_2 V_48 ;
if ( ( V_47 >= V_45 ) || ( ! V_49 . V_25 [ V_47 ] ) )
return - V_50 ;
V_48 = F_18 ( V_49 . V_25 [ V_47 ] , V_51 ) ;
return F_26 ( V_48 ) ;
}
void F_27 ( struct V_52 * V_53 )
{
F_28 ( V_49 . V_54 , V_53 ) ;
}
static int F_29 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
int V_11 = 0 ;
int V_59 = 0 ;
F_30 (np, NULL, L_9 ) {
struct V_55 * V_60 = F_31 ( V_58 ) ;
const T_3 * V_3 = F_32 ( V_58 , L_10 , NULL ) ;
struct V_61 V_62 ;
T_2 V_48 ;
int V_63 ;
if ( ! F_33 ( V_58 ) )
continue;
if ( ! V_60 ) {
F_34 ( & V_56 -> V_64 , L_11 ) ;
continue;
}
if ( ! V_3 || * V_3 >= V_45 )
continue;
if ( F_35 ( V_58 , 0 , & V_62 ) )
continue;
V_49 . V_65 [ * V_3 ] = F_36 ( & V_60 -> V_64 , NULL ) ;
if ( F_37 ( V_49 . V_65 [ * V_3 ] ) ) {
F_34 ( & V_60 -> V_64 , L_12 ) ;
return F_38 ( V_49 . V_65 [ * V_3 ] ) ;
}
V_49 . V_25 [ * V_3 ] = F_39 ( & V_56 -> V_64 ,
& V_62 ) ;
if ( F_37 ( V_49 . V_25 [ * V_3 ] ) )
return F_38 ( V_49 . V_25 [ * V_3 ] ) ;
V_48 = F_18 ( V_49 . V_25 [ * V_3 ] ,
V_51 ) ;
V_63 = F_26 ( V_48 ) ;
F_1 ( & V_66 [ V_11 ] , * V_3 , V_63 ) ;
V_11 += V_63 ;
F_40 ( V_49 . V_65 [ * V_3 ] ) ;
F_41 ( & V_56 -> V_64 , L_13 ,
V_62 . V_8 , V_63 ) ;
}
F_41 ( & V_56 -> V_64 , L_14 , V_11 ) ;
V_67 . V_8 = F_42 ( & V_56 -> V_64 ) ;
V_67 . V_68 = V_11 ;
V_49 . V_43 = V_69 ;
V_49 . V_70 = F_43 ( V_69 ) ;
V_49 . V_71 = V_72 ;
V_49 . V_73 = F_43 ( V_72 ) ;
V_49 . V_74 = V_75 ;
V_49 . V_76 = F_43 ( V_75 ) ;
V_59 = F_44 ( V_56 , & V_49 ) ;
if ( ! V_59 )
F_45 ( & V_56 -> V_64 , L_15 ) ;
return V_59 ;
}
int T_4 F_46 ( void )
{
return F_47 ( & V_77 ) ;
}
