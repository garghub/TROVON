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
unsigned long V_15 ;
struct V_36 * V_37 ;
struct V_18 * V_19 = F_6 ( V_13 ) ;
int V_38 = F_8 ( V_35 ) ;
F_20 ( V_34 , L_3 , V_38 ,
F_18 ( V_19 -> V_23 [ V_38 ] , F_21 ( F_11 ( V_35 ) ) ) ) ;
V_15 = F_9 ( V_28 , 0 ) ;
if ( ! F_5 ( V_13 , V_35 , & V_15 ) )
F_20 ( V_34 , L_4 ,
( int ) F_13 ( V_15 ) ) ;
V_15 = F_9 ( V_24 , 0 ) ;
if ( ! F_5 ( V_13 , V_35 , & V_15 ) )
F_20 ( V_34 , L_5 ,
( int ) F_13 ( V_15 ) ) ;
V_15 = F_9 ( V_26 , 0 ) ;
if ( ! F_5 ( V_13 , V_35 , & V_15 ) )
F_20 ( V_34 , L_6 ,
( int ) F_13 ( V_15 ) ) ;
V_37 = F_22 ( V_13 , V_35 ) ;
if ( V_37 ) {
if ( V_37 -> V_39 )
F_20 ( V_34 , L_7 , V_37 -> V_39 ) ;
} else {
F_20 ( V_34 , L_8 ) ;
}
}
static void F_23 ( struct V_12 * V_13 ,
struct V_33 * V_34 , unsigned V_40 )
{
}
static inline int F_24 ( struct V_12 * V_13 ,
int V_41 , int V_42 )
{
struct V_18 * V_19 = F_6 ( V_13 ) ;
int V_38 = F_8 ( V_19 -> V_41 [ V_41 ] . V_17 ) ;
if ( ( V_38 >= V_43 ) || ( ! V_19 -> V_23 [ V_38 ] ) )
return - V_44 ;
F_16 ( V_19 -> V_23 [ V_38 ] , V_42 ,
F_21 ( F_11 ( V_19 -> V_41 [ V_41 ] . V_17 ) ) ) ;
return 0 ;
}
int F_25 ( int V_45 )
{
T_2 V_46 ;
if ( ( V_45 >= V_43 ) || ( ! V_47 . V_23 [ V_45 ] ) )
return - V_48 ;
V_46 = F_18 ( V_47 . V_23 [ V_45 ] , V_49 ) ;
return F_26 ( V_46 ) ;
}
void F_27 ( struct V_50 * V_51 )
{
F_28 ( V_47 . V_52 , V_51 ) ;
}
static int F_29 ( struct V_53 * V_54 )
{
struct V_55 * V_56 ;
int V_11 = 0 ;
int V_57 = 0 ;
F_30 (np, NULL, L_9 ) {
struct V_53 * V_58 = F_31 ( V_56 ) ;
const T_3 * V_3 = F_32 ( V_56 , L_10 , NULL ) ;
struct V_59 V_60 ;
T_2 V_46 ;
int V_61 ;
if ( ! F_33 ( V_56 ) )
continue;
if ( ! V_58 ) {
F_34 ( & V_54 -> V_62 , L_11 ) ;
continue;
}
if ( ! V_3 || * V_3 >= V_43 )
continue;
if ( F_35 ( V_56 , 0 , & V_60 ) )
continue;
V_47 . V_63 [ * V_3 ] = F_36 ( & V_58 -> V_62 , NULL ) ;
if ( F_37 ( V_47 . V_63 [ * V_3 ] ) ) {
F_34 ( & V_58 -> V_62 , L_12 ) ;
return F_38 ( V_47 . V_63 [ * V_3 ] ) ;
}
V_47 . V_23 [ * V_3 ] = F_39 ( & V_54 -> V_62 ,
& V_60 ) ;
if ( F_37 ( V_47 . V_23 [ * V_3 ] ) )
return F_38 ( V_47 . V_23 [ * V_3 ] ) ;
V_46 = F_18 ( V_47 . V_23 [ * V_3 ] ,
V_49 ) ;
V_61 = F_26 ( V_46 ) ;
F_1 ( & V_64 [ V_11 ] , * V_3 , V_61 ) ;
V_11 += V_61 ;
F_40 ( V_47 . V_63 [ * V_3 ] ) ;
F_41 ( & V_54 -> V_62 , L_13 ,
V_60 . V_8 , V_61 ) ;
}
F_41 ( & V_54 -> V_62 , L_14 , V_11 ) ;
V_65 . V_8 = F_42 ( & V_54 -> V_62 ) ;
V_65 . V_66 = V_11 ;
V_47 . V_41 = V_67 ;
V_47 . V_68 = F_43 ( V_67 ) ;
V_47 . V_69 = V_70 ;
V_47 . V_71 = F_43 ( V_70 ) ;
V_47 . V_72 = V_73 ;
V_47 . V_74 = F_43 ( V_73 ) ;
V_57 = F_44 ( V_54 , & V_47 ) ;
if ( ! V_57 )
F_45 ( & V_54 -> V_62 , L_15 ) ;
return V_57 ;
}
int T_4 F_46 ( void )
{
return F_47 ( & V_75 ) ;
}
