static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = F_2 ( F_3 ( & V_2 -> V_5 ) ) ;
return V_2 -> V_6 ( V_2 -> V_7 , ( char * ) V_4 , V_4 -> V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_9 V_10 ;
V_2 -> V_11 = 0 ;
F_5 ( & V_2 -> V_5 , 0 ) ;
F_6 ( L_1 , V_2 -> V_7 ) ;
V_10 . V_12 . type = V_13 ;
V_10 . V_12 . V_8 = sizeof( struct V_9 ) ;
V_10 . V_14 = F_2 ( V_15 ) ;
F_1 ( V_2 , & V_10 . V_12 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_16 V_17 ;
V_2 -> V_11 = 0 ;
V_17 . V_12 . type = V_18 ;
V_17 . V_12 . V_8 = sizeof( struct V_16 ) ;
V_17 . V_14 = F_2 ( V_19 ) ;
return F_1 ( V_2 , & V_17 . V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_20 )
{
if ( V_20 )
V_2 -> V_21 |= V_22 ;
else {
V_2 -> V_21 &= ~ V_22 ;
if ( ! V_2 -> V_23 && V_2 -> V_24 ) {
F_6 ( L_2 ,
V_2 -> V_7 ) ;
F_7 ( V_2 ) ;
}
}
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_16 * V_25 = (struct V_16 * ) V_2 -> V_26 ;
switch ( F_10 ( V_25 -> V_14 ) ) {
case V_19 :
F_4 ( V_2 ) ;
break;
case V_27 :
F_8 ( V_2 , F_11 ( V_25 -> V_28 ) & V_29 ) ;
break;
}
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_25 = (struct V_9 * ) V_2 -> V_26 ;
struct V_30 V_31 ;
if ( F_10 ( V_25 -> V_14 ) != V_15 )
return;
F_6 ( L_3 ,
V_2 -> V_7 ) ;
V_31 . V_12 . type = V_32 ;
V_31 . V_12 . V_8 = sizeof( struct V_30 ) ;
V_31 . V_14 = F_2 ( V_15 ) ;
V_31 . V_33 . V_34 = V_35 ;
V_31 . V_36 = V_25 -> V_12 . V_5 ;
F_1 ( V_2 , & V_31 . V_12 ) ;
V_2 -> V_11 = 1 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_30 * V_31 =
(struct V_30 * ) V_2 -> V_26 ;
switch( V_31 -> V_14 ) {
case V_37 :
F_8 ( V_2 , F_11 ( V_31 -> V_33 . V_38 ) & V_29 ) ;
V_2 -> V_39 = 1 ;
break;
}
}
static int F_14 ( struct V_1 * V_2 )
{
T_1 V_8 , type ;
if ( V_2 -> V_26 [ 0 ] < 0xfc ) {
V_2 -> V_40 = V_2 -> V_41 = 0 ;
return 0 ;
}
type = V_2 -> V_26 [ 0 ] ;
V_8 = V_2 -> V_26 [ 1 ] ;
if ( V_2 -> V_40 < V_8 )
return 0 ;
F_6 ( L_4 ,
V_2 -> V_7 , type , V_8 ) ;
switch( type ) {
case V_42 :
V_2 -> V_41 = V_8 - 4 ;
V_2 -> V_43 = 4 ;
return 1 ;
case V_18 :
F_9 ( V_2 ) ;
break;
case V_13 :
F_12 ( V_2 ) ;
break;
case V_32 :
F_13 ( V_2 ) ;
break;
}
V_2 -> V_40 -= V_8 ;
memmove ( V_2 -> V_26 , & V_2 -> V_26 [ V_8 ] , V_2 -> V_40 ) ;
return 1 ;
}
static int F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 < V_44 )
V_2 -> V_40 += V_2 -> V_45 ( V_2 -> V_7 ,
& V_2 -> V_26 [ V_2 -> V_40 ] ,
V_44 - V_2 -> V_40 ) ;
if ( V_2 -> V_40 >= 4 )
return F_14 ( V_2 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , char * V_46 , int V_47 )
{
unsigned int V_48 , V_49 = 0 ;
if ( F_17 ( ! V_2 ) )
return - V_50 ;
if ( ! V_2 -> V_24 )
return 0 ;
for ( V_48 = 1 ; V_47 && V_48 < 2 ; V_48 ++ ) {
if ( V_2 -> V_41 ) {
unsigned int V_51 = F_18 ( V_47 , ( int ) V_2 -> V_41 ) ;
memcpy ( & V_46 [ V_49 ] , & V_2 -> V_26 [ V_2 -> V_43 ] , V_51 ) ;
V_2 -> V_43 += V_51 ;
V_2 -> V_41 -= V_51 ;
V_47 -= V_51 ;
V_49 += V_51 ;
}
if ( V_47 == 0 )
break;
if ( V_2 -> V_43 ) {
V_2 -> V_40 -= V_2 -> V_43 ;
memmove ( V_2 -> V_26 , & V_2 -> V_26 [ V_2 -> V_43 ] ,
V_2 -> V_40 ) ;
V_2 -> V_43 = 0 ;
}
if ( F_15 ( V_2 ) )
V_48 -- ;
}
if ( ! V_2 -> V_11 ) {
F_6 ( L_5 , V_2 -> V_7 ) ;
return - V_52 ;
}
return V_49 ;
}
int F_19 ( struct V_1 * V_2 , const char * V_46 , int V_47 )
{
struct V_53 V_54 ;
int V_55 , V_56 = F_18 ( V_47 , V_57 ) ;
if ( F_17 ( ! V_2 ) )
return - V_58 ;
V_54 . V_12 . type = V_42 ;
V_54 . V_12 . V_8 = V_56 + sizeof( struct V_3 ) ;
memcpy ( V_54 . V_59 , V_46 , V_56 ) ;
V_55 = F_1 ( V_2 , & V_54 . V_12 ) ;
if ( V_55 <= 0 )
return V_55 ;
return V_56 ;
}
static void F_20 ( unsigned long V_60 )
{
if ( F_21 () )
F_22 ( V_60 ) ;
else
F_23 ( V_60 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_9 V_10 ;
int V_55 , V_61 ;
F_6 ( L_6 ,
V_2 -> V_7 ) ;
V_2 -> V_39 = 0 ;
V_10 . V_12 . type = V_13 ;
V_10 . V_12 . V_8 = sizeof( struct V_9 ) ;
V_10 . V_14 = F_2 ( V_37 ) ;
V_55 = F_1 ( V_2 , & V_10 . V_12 ) ;
if ( V_55 <= 0 ) {
F_6 ( L_7 , V_2 -> V_7 , V_55 ) ;
return V_55 ;
}
for ( V_61 = 0 ; V_61 < 20 ; V_61 ++ ) {
if ( ! V_2 -> V_11 )
return - V_50 ;
if ( V_2 -> V_39 )
return 0 ;
if ( ! F_15 ( V_2 ) )
F_20 ( 10 ) ;
}
return - V_62 ;
}
int F_25 ( struct V_1 * V_2 , int V_63 )
{
struct V_16 V_17 ;
unsigned short V_21 ;
V_21 = V_2 -> V_21 ;
if ( V_63 )
V_21 |= V_64 ;
else
V_21 &= ~ V_64 ;
if ( V_21 == V_2 -> V_21 )
return 0 ;
V_2 -> V_21 = V_21 ;
F_6 ( L_8 , V_2 -> V_7 ,
V_63 ? L_9 : L_10 ) ;
V_17 . V_12 . type = V_18 ,
V_17 . V_12 . V_8 = sizeof( struct V_16 ) ;
V_17 . V_14 = F_2 ( V_65 ) ;
V_17 . V_66 = F_26 ( V_67 ) ;
V_17 . V_28 = F_26 ( V_63 ? V_67 : 0 ) ;
return F_1 ( V_2 , & V_17 . V_12 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
int V_61 ;
F_6 ( L_11 , V_2 -> V_7 ) ;
for ( V_61 = 0 ; V_61 < 20 ; V_61 ++ ) {
if ( V_2 -> V_11 )
goto V_11;
if ( ! F_15 ( V_2 ) )
F_20 ( 10 ) ;
}
F_6 ( L_12 , V_2 -> V_7 ) ;
F_7 ( V_2 ) ;
F_6 ( L_13 , V_2 -> V_7 ) ;
F_4 ( V_2 ) ;
F_6 ( L_14 , V_2 -> V_7 ) ;
for ( V_61 = 0 ; V_61 < 40 ; V_61 ++ ) {
if ( V_2 -> V_11 )
goto V_11;
if ( ! F_15 ( V_2 ) )
F_20 ( 10 ) ;
}
if ( ! V_2 -> V_11 ) {
F_6 ( L_15 ,
V_2 -> V_7 ) ;
return;
}
V_11:
F_6 ( L_16 , V_2 -> V_7 ) ;
F_24 ( V_2 ) ;
F_6 ( L_17 , V_2 -> V_7 ) ;
F_25 ( V_2 , 1 ) ;
F_28 () ;
V_2 -> V_24 = 1 ;
}
int F_29 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
F_6 ( L_18 , V_2 -> V_7 ) ;
V_2 -> V_70 = F_30 ( & V_69 -> V_71 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
void F_31 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
unsigned long V_72 ;
F_6 ( L_19 , V_2 -> V_7 ) ;
if ( ! V_2 -> V_23 ) {
F_6 ( L_20 ,
V_2 -> V_7 ) ;
F_32 ( & V_69 -> V_73 , V_72 ) ;
V_2 -> V_24 = 0 ;
F_33 ( & V_69 -> V_73 , V_72 ) ;
if ( ! V_2 -> V_70 || ( V_2 -> V_70 -> V_74 . V_75 & V_76 ) )
F_25 ( V_2 , 0 ) ;
F_7 ( V_2 ) ;
}
F_34 ( V_2 -> V_70 ) ;
V_2 -> V_70 = NULL ;
}
void F_35 ( struct V_1 * V_2 ,
int (* V_45)( T_2 V_7 , char * V_46 , int V_47 ) ,
int (* V_6)( T_2 V_7 , const char * V_46 ,
int V_47 ) ,
int V_7 , int V_23 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_45 = V_45 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_23 = V_23 ;
}
