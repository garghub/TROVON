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
return 0 ;
}
if ( F_16 ( V_30 -> V_33 ) ) {
if ( F_16 ( V_13 -> V_34 <= V_35 ) ) {
V_13 -> V_36 = NULL ;
F_17 ( V_13 , V_30 -> V_33 ) ;
return 0 ;
}
}
F_8 ( V_13 ) ;
return 0 ;
}
static void F_18 ( struct V_37 * V_38 )
{
struct V_20 * V_30 =
F_19 ( V_38 , struct V_20 , V_39 ) ;
F_20 ( & V_30 -> V_40 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_20 * V_30 = & V_41 [ 0 ] ;
struct V_20 * V_42 = & V_41 [ V_43 ] ;
char * V_44 = strchr ( ( const char * ) V_2 -> V_45 , ':' ) + 1 ;
int V_46 = 0 ;
while ( V_30 -> V_17 ) {
if ( ! V_30 -> V_33 )
V_46 ++ ;
if ( ++ V_30 == V_42 )
return V_46 ? - V_47 : - V_48 ;
}
V_17 = F_22 ( & V_32 , V_44 ) ;
if ( ! V_17 )
return - V_49 ;
V_30 -> V_17 = V_17 ;
V_30 -> V_40 . type = F_10 ( V_24 ) ;
V_30 -> V_40 . V_17 = V_17 ;
V_30 -> V_40 . V_50 = F_13 ;
V_30 -> V_40 . V_31 = V_30 ;
F_23 ( & ( V_30 -> V_40 . V_51 ) ) ;
F_24 ( & V_30 -> V_39 , F_18 ) ;
F_25 ( & V_30 -> V_39 ) ;
V_30 -> V_33 = V_2 ;
V_2 -> V_21 = ( void * ) V_30 ;
memset ( V_2 -> V_11 . V_6 , 0 , sizeof( V_2 -> V_11 . V_6 ) ) ;
memcpy ( V_2 -> V_11 . V_6 , V_17 -> V_10 , V_7 ) ;
V_2 -> V_11 . V_8 = V_9 ;
V_2 -> V_11 . V_10 = 1 ;
V_2 -> V_52 = V_17 -> V_52 ;
V_2 -> V_53 = 0 ;
F_1 ( V_2 , & V_2 -> V_54 , ( char * ) V_17 -> V_25 ) ;
return 0 ;
}
static void F_26 ( struct V_37 * V_38 )
{
struct V_20 * V_30 =
F_19 ( V_38 , struct V_20 , V_55 ) ;
F_27 ( & V_30 -> V_40 ) ;
F_28 ( V_30 -> V_17 ) ;
V_30 -> V_17 = NULL ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_20 * V_30 = (struct V_20 * ) V_2 -> V_21 ;
V_30 -> V_33 = NULL ;
F_24 ( & V_30 -> V_55 , F_26 ) ;
F_25 ( & V_30 -> V_55 ) ;
}
static int F_30 ( struct V_56 * V_57 , unsigned long V_58 ,
void * V_59 )
{
struct V_16 * V_17 = F_31 ( V_59 ) ;
struct V_20 * V_30 = & V_41 [ 0 ] ;
struct V_20 * V_42 = & V_41 [ V_43 ] ;
if ( ! F_14 ( F_15 ( V_17 ) , & V_32 ) )
return V_60 ;
while ( ( V_30 -> V_17 != V_17 ) ) {
if ( ++ V_30 == V_42 )
return V_60 ;
}
if ( ! V_30 -> V_33 )
return V_60 ;
V_30 -> V_33 -> V_52 = V_17 -> V_52 ;
switch ( V_58 ) {
case V_61 :
if ( F_32 ( V_17 ) )
F_33 ( V_30 -> V_33 ) ;
else
F_34 ( V_30 -> V_33 -> V_45 ) ;
break;
case V_62 :
F_33 ( V_30 -> V_33 ) ;
break;
case V_63 :
F_34 ( V_30 -> V_33 -> V_45 ) ;
break;
case V_64 :
case V_65 :
F_34 ( V_30 -> V_33 -> V_45 ) ;
F_33 ( V_30 -> V_33 ) ;
break;
case V_66 :
case V_67 :
F_35 ( V_30 -> V_33 -> V_45 ) ;
break;
}
return V_68 ;
}
static int F_36 ( struct V_3 * V_4 , char * V_69 , int V_70 )
{
if ( V_70 < 60 )
return 1 ;
sprintf ( V_69 , L_1 , V_4 -> V_6 ) ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 , char * V_71 )
{
memset ( V_71 , 0 , V_72 ) ;
V_71 [ V_73 ] = V_9 ;
memcpy ( V_71 , V_4 -> V_6 , V_7 ) ;
return 0 ;
}
static int F_38 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_71 )
{
F_1 ( V_2 , V_4 , V_71 ) ;
return 0 ;
}
int F_39 ( void )
{
int V_74 ;
if ( V_75 )
return - V_76 ;
V_74 = F_40 ( & V_77 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_41 ( & V_78 ) ;
if ( ! V_74 )
V_75 = 1 ;
return V_74 ;
}
void F_42 ( void )
{
if ( ! V_75 )
return;
F_43 () ;
F_44 ( & V_78 ) ;
V_75 = 0 ;
}
