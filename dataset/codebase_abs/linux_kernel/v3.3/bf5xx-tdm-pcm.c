static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_3 ) ;
}
static int F_3 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
T_1 V_7 = V_8 . V_9 ;
F_4 ( V_4 , V_7 * 4 ) ;
return 0 ;
}
static int F_5 ( struct V_2 * V_4 )
{
F_6 ( V_4 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_15 = F_8 ( V_11 , V_11 -> V_16 ) ;
V_15 /= V_11 -> V_17 ;
V_15 *= 8 ;
if ( V_4 -> V_18 == V_19 ) {
F_9 ( V_13 , F_1 , V_4 ) ;
F_10 ( V_13 , V_11 -> V_20 ,
V_11 -> V_21 , V_15 ) ;
} else {
F_11 ( V_13 , F_1 , V_4 ) ;
F_12 ( V_13 , V_11 -> V_20 ,
V_11 -> V_21 , V_15 ) ;
}
return 0 ;
}
static int F_13 ( struct V_2 * V_4 , int V_22 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_23 = 0 ;
switch ( V_22 ) {
case V_24 :
if ( V_4 -> V_18 == V_19 )
F_14 ( V_13 ) ;
else
F_15 ( V_13 ) ;
break;
case V_25 :
case V_26 :
case V_27 :
if ( V_4 -> V_18 == V_19 )
F_16 ( V_13 ) ;
else
F_17 ( V_13 ) ;
break;
default:
V_23 = - V_28 ;
}
return V_23 ;
}
static T_2 F_18 ( struct V_2 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
unsigned int V_29 ;
T_2 V_30 ;
if ( V_4 -> V_18 == V_19 ) {
V_29 = F_19 ( V_13 ) ;
V_30 = V_29 / ( 8 * 4 ) ;
} else {
V_29 = F_20 ( V_13 ) ;
V_30 = V_29 / ( 8 * 4 ) ;
}
return V_30 ;
}
static int F_21 ( struct V_2 * V_4 )
{
struct V_31 * V_32 = V_4 -> V_14 ;
struct V_33 * V_34 = V_32 -> V_34 ;
struct V_12 * V_35 = F_22 ( V_34 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_36 * V_37 = & V_4 -> V_38 ;
int V_23 = 0 ;
F_23 ( V_4 , & V_8 ) ;
V_23 = F_24 ( V_11 ,
V_39 ) ;
if ( V_23 < 0 )
goto V_40;
if ( V_35 != NULL ) {
if ( V_4 -> V_18 == V_19 )
V_35 -> V_41 = V_37 -> V_42 ;
else
V_35 -> V_43 = V_37 -> V_42 ;
V_11 -> V_14 = V_35 ;
} else {
F_25 ( L_1 ) ;
V_23 = - V_44 ;
}
V_40:
return V_23 ;
}
static int F_26 ( struct V_2 * V_4 , int V_45 ,
T_2 V_46 , void * V_37 , T_2 V_47 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_48 * V_49 = V_13 -> V_14 ;
unsigned int * V_50 ;
unsigned int * V_51 ;
int V_52 ;
if ( V_4 -> V_18 == V_19 ) {
V_50 = V_37 ;
V_51 = ( unsigned int * ) V_4 -> V_11 -> V_20 ;
V_51 += V_46 * 8 ;
while ( V_47 -- ) {
for ( V_52 = 0 ; V_52 < V_4 -> V_11 -> V_17 ; V_52 ++ )
* ( V_51 + V_49 -> V_53 [ V_52 ] ) = * V_50 ++ ;
V_51 += 8 ;
}
} else {
V_50 = ( unsigned int * ) V_4 -> V_11 -> V_20 ;
V_51 = V_37 ;
V_50 += V_46 * 8 ;
while ( V_47 -- ) {
for ( V_52 = 0 ; V_52 < V_4 -> V_11 -> V_17 ; V_52 ++ )
* V_51 ++ = * ( V_50 + V_49 -> V_54 [ V_52 ] ) ;
V_50 += 8 ;
}
}
return 0 ;
}
static int F_27 ( struct V_2 * V_4 ,
int V_45 , T_2 V_46 , T_2 V_47 )
{
unsigned char * V_37 = V_4 -> V_11 -> V_20 ;
V_37 += V_46 * 8 * 4 ;
memset ( V_37 , '\0' , V_47 * 8 * 4 ) ;
return 0 ;
}
static int F_28 ( struct V_55 * V_3 , int V_18 )
{
struct V_2 * V_4 = V_3 -> V_56 [ V_18 ] . V_4 ;
struct V_36 * V_37 = & V_4 -> V_38 ;
T_1 V_7 = V_8 . V_9 ;
V_37 -> V_57 . type = V_58 ;
V_37 -> V_57 . V_57 = V_3 -> V_59 -> V_57 ;
V_37 -> V_14 = NULL ;
V_37 -> V_42 = F_29 ( V_3 -> V_59 -> V_57 , V_7 * 4 ,
& V_37 -> V_60 , V_61 ) ;
if ( ! V_37 -> V_42 ) {
F_25 ( L_2 ) ;
return - V_62 ;
}
V_37 -> V_63 = V_7 ;
return 0 ;
}
static void F_30 ( struct V_55 * V_3 )
{
struct V_2 * V_4 ;
struct V_36 * V_37 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 2 ; V_18 ++ ) {
V_4 = V_3 -> V_56 [ V_18 ] . V_4 ;
if ( ! V_4 )
continue;
V_37 = & V_4 -> V_38 ;
if ( ! V_37 -> V_42 )
continue;
F_31 ( NULL , V_37 -> V_63 , V_37 -> V_42 , 0 ) ;
V_37 -> V_42 = NULL ;
}
}
static int F_32 ( struct V_31 * V_32 )
{
struct V_64 * V_59 = V_32 -> V_59 -> V_64 ;
struct V_55 * V_3 = V_32 -> V_3 ;
int V_23 = 0 ;
if ( ! V_59 -> V_57 -> V_65 )
V_59 -> V_57 -> V_65 = & V_66 ;
if ( ! V_59 -> V_57 -> V_67 )
V_59 -> V_57 -> V_67 = F_33 ( 32 ) ;
if ( V_3 -> V_56 [ V_19 ] . V_4 ) {
V_23 = F_28 ( V_3 ,
V_19 ) ;
if ( V_23 )
goto V_40;
}
if ( V_3 -> V_56 [ V_68 ] . V_4 ) {
V_23 = F_28 ( V_3 ,
V_68 ) ;
if ( V_23 )
goto V_40;
}
V_40:
return V_23 ;
}
static int T_3 F_34 ( struct V_69 * V_70 )
{
return F_35 ( & V_70 -> V_57 , & V_71 ) ;
}
static int T_4 F_36 ( struct V_69 * V_70 )
{
F_37 ( & V_70 -> V_57 ) ;
return 0 ;
}
