static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 (lapbeth, &lapbeth_devices, node) {
if ( V_4 -> V_5 == V_3 )
return V_4 ;
}
return NULL ;
}
static T_1 int F_3 ( struct V_2 * V_3 )
{
return V_3 -> type == V_6 && strncmp ( V_3 -> V_7 , L_1 , 5 ) ;
}
static int F_4 ( struct V_8 * V_9 , struct V_2 * V_3 , struct V_10 * V_11 , struct V_2 * V_12 )
{
int V_13 , V_14 ;
struct V_1 * V_4 ;
if ( F_5 ( V_3 ) != & V_15 )
goto V_16;
if ( ( V_9 = F_6 ( V_9 , V_17 ) ) == NULL )
return V_18 ;
if ( ! F_7 ( V_9 , 2 ) )
goto V_16;
F_8 () ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
goto V_19;
if ( ! F_9 ( V_4 -> V_20 ) )
goto V_19;
V_13 = V_9 -> V_21 [ 0 ] + V_9 -> V_21 [ 1 ] * 256 ;
V_3 -> V_22 . V_23 ++ ;
V_3 -> V_22 . V_24 += V_13 ;
F_10 ( V_9 , 2 ) ;
F_11 ( V_9 , V_13 ) ;
if ( ( V_14 = F_12 ( V_4 -> V_20 , V_9 ) ) != V_25 ) {
F_13 ( V_26 L_2 , V_14 ) ;
goto V_19;
}
V_27:
F_14 () ;
return 0 ;
V_19:
F_15 ( V_9 ) ;
goto V_27;
V_16:
F_15 ( V_9 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
unsigned char * V_28 ;
F_17 ( V_9 , 1 ) ;
if ( F_18 ( V_9 , 1 ) )
return V_18 ;
V_28 = V_9 -> V_21 ;
* V_28 = V_29 ;
V_9 -> V_30 = F_19 ( V_9 , V_3 ) ;
return F_20 ( V_9 ) ;
}
static T_2 F_21 ( struct V_8 * V_9 ,
struct V_2 * V_3 )
{
int V_14 ;
if ( ! F_9 ( V_3 ) )
goto V_16;
switch ( V_9 -> V_21 [ 0 ] ) {
case V_29 :
break;
case V_31 :
if ( ( V_14 = F_22 ( V_3 ) ) != V_25 )
F_23 ( L_3 , V_14 ) ;
goto V_16;
case V_32 :
if ( ( V_14 = F_24 ( V_3 ) ) != V_25 )
F_23 ( L_4 , V_14 ) ;
default:
goto V_16;
}
F_10 ( V_9 , 1 ) ;
if ( ( V_14 = F_25 ( V_3 , V_9 ) ) != V_25 ) {
F_23 ( L_5 , V_14 ) ;
goto V_16;
}
V_27:
return V_33 ;
V_16:
F_15 ( V_9 ) ;
goto V_27;
}
static void F_26 ( struct V_2 * V_34 , struct V_8 * V_9 )
{
struct V_1 * V_4 = F_27 ( V_34 ) ;
unsigned char * V_28 ;
struct V_2 * V_3 ;
int V_35 = V_9 -> V_13 ;
V_9 -> V_30 = F_28 ( V_36 ) ;
V_28 = F_17 ( V_9 , 2 ) ;
* V_28 ++ = V_35 % 256 ;
* V_28 ++ = V_35 / 256 ;
V_34 -> V_22 . V_37 ++ ;
V_34 -> V_22 . V_38 += V_35 ;
V_9 -> V_3 = V_3 = V_4 -> V_5 ;
F_29 ( V_9 , V_3 , V_39 , V_40 , NULL , 0 ) ;
F_30 ( V_9 ) ;
}
static void F_31 ( struct V_2 * V_3 , int V_41 )
{
unsigned char * V_28 ;
struct V_8 * V_9 = F_32 ( 1 ) ;
if ( ! V_9 ) {
F_23 ( L_6 ) ;
return;
}
V_28 = F_33 ( V_9 , 1 ) ;
* V_28 = V_31 ;
V_9 -> V_30 = F_19 ( V_9 , V_3 ) ;
F_20 ( V_9 ) ;
}
static void F_34 ( struct V_2 * V_3 , int V_41 )
{
unsigned char * V_28 ;
struct V_8 * V_9 = F_32 ( 1 ) ;
if ( ! V_9 ) {
F_23 ( L_6 ) ;
return;
}
V_28 = F_33 ( V_9 , 1 ) ;
* V_28 = V_32 ;
V_9 -> V_30 = F_19 ( V_9 , V_3 ) ;
F_20 ( V_9 ) ;
}
static int F_35 ( struct V_2 * V_3 , void * V_42 )
{
struct V_43 * V_44 = V_42 ;
memcpy ( V_3 -> V_45 , V_44 -> V_46 , V_3 -> V_47 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 )
{
int V_14 ;
if ( ( V_14 = F_37 ( V_3 , & V_48 ) ) != V_25 ) {
F_23 ( L_7 , V_14 ) ;
return - V_49 ;
}
F_38 ( V_3 ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 )
{
int V_14 ;
F_40 ( V_3 ) ;
if ( ( V_14 = F_41 ( V_3 ) ) != V_25 )
F_23 ( L_8 , V_14 ) ;
return 0 ;
}
static void F_42 ( struct V_2 * V_3 )
{
V_3 -> V_50 = & V_51 ;
V_3 -> V_52 = V_53 ;
V_3 -> type = V_54 ;
V_3 -> V_55 = 3 ;
V_3 -> V_56 = 1000 ;
V_3 -> V_47 = 0 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_2 * V_34 ;
struct V_1 * V_4 ;
int V_57 = - V_58 ;
F_44 () ;
V_34 = F_45 ( sizeof( * V_4 ) , L_9 ,
F_42 ) ;
if ( ! V_34 )
goto V_27;
V_4 = F_27 ( V_34 ) ;
V_4 -> V_20 = V_34 ;
F_46 ( V_3 ) ;
V_4 -> V_5 = V_3 ;
V_57 = - V_59 ;
if ( F_47 ( V_34 ) )
goto V_60;
F_48 ( & V_4 -> V_61 , & V_62 ) ;
V_57 = 0 ;
V_27:
return V_57 ;
V_60:
F_49 ( V_3 ) ;
V_53 ( V_34 ) ;
F_50 ( V_4 ) ;
goto V_27;
}
static void F_51 ( struct V_1 * V_4 )
{
F_49 ( V_4 -> V_5 ) ;
F_52 ( & V_4 -> V_61 ) ;
F_53 ( V_4 -> V_20 ) ;
}
static int F_54 ( struct V_63 * V_64 ,
unsigned long V_65 , void * V_28 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 = V_28 ;
if ( F_5 ( V_3 ) != & V_15 )
return V_66 ;
if ( ! F_3 ( V_3 ) )
return V_66 ;
switch ( V_65 ) {
case V_67 :
if ( F_1 ( V_3 ) == NULL )
F_43 ( V_3 ) ;
break;
case V_68 :
V_4 = F_1 ( V_3 ) ;
if ( V_4 )
F_55 ( V_4 -> V_20 ) ;
break;
case V_69 :
V_4 = F_1 ( V_3 ) ;
if ( V_4 )
F_51 ( V_4 ) ;
break;
}
return V_66 ;
}
static int T_3 F_56 ( void )
{
F_57 ( & V_70 ) ;
F_58 ( & V_71 ) ;
F_13 ( V_72 ) ;
return 0 ;
}
static void T_4 F_59 ( void )
{
struct V_1 * V_4 ;
struct V_73 * V_74 , * V_75 ;
F_60 ( & V_70 ) ;
F_61 ( & V_71 ) ;
F_62 () ;
F_63 (entry, tmp, &lapbeth_devices) {
V_4 = F_64 ( V_74 , struct V_1 , V_61 ) ;
F_49 ( V_4 -> V_5 ) ;
F_53 ( V_4 -> V_20 ) ;
}
F_65 () ;
}
