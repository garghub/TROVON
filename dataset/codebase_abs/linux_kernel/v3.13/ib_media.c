static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
F_2 ( sizeof( V_4 -> V_6 ) < V_7 ) ;
memcpy ( V_4 -> V_6 , V_5 , V_7 ) ;
V_4 -> V_8 = V_9 ;
V_4 -> V_10 = ! memcmp ( V_5 , V_2 -> V_11 . V_6 , V_7 ) ;
}
static int F_3 ( struct V_12 * V_13 , struct V_1 * V_2 ,
struct V_3 * V_14 )
{
struct V_12 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
V_15 = F_4 ( V_13 , V_19 ) ;
if ( ! V_15 )
return 0 ;
V_17 = ( (struct V_20 * ) ( V_2 -> V_21 ) ) -> V_17 ;
V_18 = V_17 -> V_22 - F_5 ( V_13 ) ;
if ( ( V_18 > 0 ) &&
F_6 ( V_15 , F_7 ( V_18 ) , 0 , V_19 ) ) {
F_8 ( V_15 ) ;
return 0 ;
}
F_9 ( V_15 ) ;
V_15 -> V_17 = V_17 ;
V_15 -> V_23 = F_10 ( V_24 ) ;
F_11 ( V_15 , V_17 , V_24 , V_14 -> V_6 ,
V_17 -> V_25 , V_15 -> V_26 ) ;
F_12 ( V_15 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_13 , struct V_16 * V_17 ,
struct V_27 * V_28 , struct V_16 * V_29 )
{
struct V_20 * V_30 = (struct V_20 * ) V_28 -> V_31 ;
if ( ! F_14 ( F_15 ( V_17 ) , & V_32 ) ) {
F_8 ( V_13 ) ;
return V_33 ;
}
if ( F_16 ( V_30 -> V_34 ) ) {
if ( F_16 ( V_13 -> V_35 <= V_36 ) ) {
V_13 -> V_37 = NULL ;
F_17 ( V_13 , V_30 -> V_34 ) ;
return V_38 ;
}
}
F_8 ( V_13 ) ;
return V_33 ;
}
static void F_18 ( struct V_39 * V_40 )
{
struct V_20 * V_30 =
F_19 ( V_40 , struct V_20 , V_41 ) ;
F_20 ( & V_30 -> V_42 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_20 * V_30 = & V_43 [ 0 ] ;
struct V_20 * V_44 = & V_43 [ V_45 ] ;
char * V_46 = strchr ( ( const char * ) V_2 -> V_47 , ':' ) + 1 ;
int V_48 = 0 ;
while ( V_30 -> V_17 ) {
if ( ! V_30 -> V_34 )
V_48 ++ ;
if ( ++ V_30 == V_44 )
return V_48 ? - V_49 : - V_50 ;
}
V_17 = F_22 ( & V_32 , V_46 ) ;
if ( ! V_17 )
return - V_51 ;
V_30 -> V_17 = V_17 ;
V_30 -> V_42 . type = F_10 ( V_24 ) ;
V_30 -> V_42 . V_17 = V_17 ;
V_30 -> V_42 . V_52 = F_13 ;
V_30 -> V_42 . V_31 = V_30 ;
F_23 ( & ( V_30 -> V_42 . V_53 ) ) ;
F_24 ( & V_30 -> V_41 , F_18 ) ;
F_25 ( & V_30 -> V_41 ) ;
V_30 -> V_34 = V_2 ;
V_2 -> V_21 = ( void * ) V_30 ;
memset ( V_2 -> V_11 . V_6 , 0 , sizeof( V_2 -> V_11 . V_6 ) ) ;
memcpy ( V_2 -> V_11 . V_6 , V_17 -> V_10 , V_7 ) ;
V_2 -> V_11 . V_8 = V_9 ;
V_2 -> V_11 . V_10 = 1 ;
V_2 -> V_54 = V_17 -> V_54 ;
V_2 -> V_55 = 0 ;
F_1 ( V_2 , & V_2 -> V_56 , ( char * ) V_17 -> V_25 ) ;
return 0 ;
}
static void F_26 ( struct V_39 * V_40 )
{
struct V_20 * V_30 =
F_19 ( V_40 , struct V_20 , V_57 ) ;
F_27 ( & V_30 -> V_42 ) ;
F_28 ( V_30 -> V_17 ) ;
V_30 -> V_17 = NULL ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_20 * V_30 = (struct V_20 * ) V_2 -> V_21 ;
V_30 -> V_34 = NULL ;
F_24 ( & V_30 -> V_57 , F_26 ) ;
F_25 ( & V_30 -> V_57 ) ;
}
static int F_30 ( struct V_58 * V_59 , unsigned long V_60 ,
void * V_61 )
{
struct V_16 * V_17 = F_31 ( V_61 ) ;
struct V_20 * V_30 = & V_43 [ 0 ] ;
struct V_20 * V_44 = & V_43 [ V_45 ] ;
if ( ! F_14 ( F_15 ( V_17 ) , & V_32 ) )
return V_62 ;
while ( ( V_30 -> V_17 != V_17 ) ) {
if ( ++ V_30 == V_44 )
return V_62 ;
}
if ( ! V_30 -> V_34 )
return V_62 ;
V_30 -> V_34 -> V_54 = V_17 -> V_54 ;
switch ( V_60 ) {
case V_63 :
if ( F_32 ( V_17 ) )
F_33 ( V_30 -> V_34 ) ;
else
F_34 ( V_30 -> V_34 ) ;
break;
case V_64 :
F_33 ( V_30 -> V_34 ) ;
break;
case V_65 :
F_34 ( V_30 -> V_34 ) ;
break;
case V_66 :
case V_67 :
F_34 ( V_30 -> V_34 ) ;
F_33 ( V_30 -> V_34 ) ;
break;
case V_68 :
case V_69 :
F_35 ( V_30 -> V_34 -> V_47 ) ;
break;
}
return V_70 ;
}
static int F_36 ( struct V_3 * V_4 , char * V_71 , int V_72 )
{
if ( V_72 < 60 )
return 1 ;
sprintf ( V_71 , L_1 , V_4 -> V_6 ) ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 , char * V_73 )
{
memset ( V_73 , 0 , V_74 ) ;
V_73 [ V_75 ] = V_9 ;
memcpy ( V_73 , V_4 -> V_6 , V_7 ) ;
return 0 ;
}
static int F_38 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_73 )
{
F_1 ( V_2 , V_4 , V_73 ) ;
return 0 ;
}
int F_39 ( void )
{
int V_76 ;
if ( V_77 )
return - V_78 ;
V_76 = F_40 ( & V_79 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_41 ( & V_80 ) ;
if ( ! V_76 )
V_77 = 1 ;
return V_76 ;
}
void F_42 ( void )
{
if ( ! V_77 )
return;
F_43 () ;
F_44 ( & V_80 ) ;
V_77 = 0 ;
}
