static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
V_7 = F_2 ( V_2 , V_11 ) ;
if ( ! V_7 )
return 0 ;
V_9 = ( (struct V_12 * ) ( V_4 -> V_13 ) ) -> V_9 ;
V_10 = V_9 -> V_14 - F_3 ( V_2 ) ;
if ( ( V_10 > 0 ) &&
F_4 ( V_7 , F_5 ( V_10 ) , 0 , V_11 ) ) {
F_6 ( V_7 ) ;
return 0 ;
}
F_7 ( V_7 ) ;
V_7 -> V_9 = V_9 ;
F_8 ( V_7 , V_9 , V_15 , & V_6 -> V_16 . V_17 ,
V_9 -> V_16 , V_7 -> V_18 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_19 * V_20 , struct V_8 * V_21 )
{
struct V_12 * V_22 = (struct V_12 * ) V_20 -> V_23 ;
if ( ! F_11 ( F_12 ( V_9 ) , & V_24 ) ) {
F_6 ( V_2 ) ;
return 0 ;
}
if ( F_13 ( V_22 -> V_25 ) ) {
if ( F_13 ( V_2 -> V_26 <= V_27 ) ) {
V_2 -> V_28 = NULL ;
F_14 ( V_2 , V_22 -> V_25 ) ;
return 0 ;
}
}
F_6 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = NULL ;
struct V_8 * V_29 = NULL ;
struct V_12 * V_22 = & V_30 [ 0 ] ;
struct V_12 * V_31 = & V_30 [ V_32 ] ;
char * V_33 = strchr ( ( const char * ) V_4 -> V_34 , ':' ) + 1 ;
int V_35 = 0 ;
while ( V_22 -> V_9 ) {
if ( ! V_22 -> V_25 )
V_35 ++ ;
if ( ++ V_22 == V_31 )
return V_35 ? - V_36 : - V_37 ;
}
F_16 (&init_net, pdev) {
if ( ! strncmp ( V_29 -> V_34 , V_33 , V_38 ) ) {
V_9 = V_29 ;
break;
}
}
if ( ! V_9 )
return - V_39 ;
while ( ( V_22 != V_31 ) && V_22 -> V_9 && ( V_22 -> V_9 != V_9 ) )
V_22 ++ ;
if ( V_22 == V_31 )
return - V_37 ;
if ( ! V_22 -> V_9 ) {
V_22 -> V_9 = V_9 ;
V_22 -> V_40 . type = F_17 ( V_15 ) ;
V_22 -> V_40 . V_9 = V_9 ;
V_22 -> V_40 . V_41 = F_10 ;
V_22 -> V_40 . V_23 = V_22 ;
F_18 ( & ( V_22 -> V_40 . V_42 ) ) ;
F_19 ( V_9 ) ;
F_20 ( & V_22 -> V_40 ) ;
}
V_22 -> V_25 = V_4 ;
V_4 -> V_13 = ( void * ) V_22 ;
V_4 -> V_43 = V_9 -> V_43 ;
V_4 -> V_44 = 0 ;
V_4 -> V_45 . type = F_21 ( V_46 ) ;
memcpy ( & V_4 -> V_45 . V_16 , V_9 -> V_16 , V_47 ) ;
return 0 ;
}
static void F_22 ( struct V_3 * V_4 )
{
( (struct V_12 * ) V_4 -> V_13 ) -> V_25 = NULL ;
}
static int F_23 ( struct V_48 * V_49 , unsigned long V_50 ,
void * V_51 )
{
struct V_8 * V_9 = (struct V_8 * ) V_51 ;
struct V_12 * V_22 = & V_30 [ 0 ] ;
struct V_12 * V_31 = & V_30 [ V_32 ] ;
if ( ! F_11 ( F_12 ( V_9 ) , & V_24 ) )
return V_52 ;
while ( ( V_22 -> V_9 != V_9 ) ) {
if ( ++ V_22 == V_31 )
return V_52 ;
}
if ( ! V_22 -> V_25 )
return V_52 ;
V_22 -> V_25 -> V_43 = V_9 -> V_43 ;
switch ( V_50 ) {
case V_53 :
if ( F_24 ( V_9 ) )
F_25 ( V_22 -> V_25 ) ;
else
F_26 ( V_22 -> V_25 -> V_34 ) ;
break;
case V_54 :
F_25 ( V_22 -> V_25 ) ;
break;
case V_55 :
F_26 ( V_22 -> V_25 -> V_34 ) ;
break;
case V_56 :
case V_57 :
F_26 ( V_22 -> V_25 -> V_34 ) ;
F_25 ( V_22 -> V_25 ) ;
break;
case V_58 :
case V_59 :
F_27 ( V_22 -> V_25 -> V_34 ) ;
break;
}
return V_60 ;
}
static char * F_28 ( struct V_5 * V_61 , char * V_62 , int V_63 )
{
T_1 * V_45 = ( T_1 * ) & V_61 -> V_16 ;
if ( V_63 < 18 )
* V_62 = '\0' ;
else
sprintf ( V_62 , L_1 , V_45 ) ;
return V_62 ;
}
int F_29 ( void )
{
struct V_5 V_64 ;
int V_65 ;
if ( V_66 )
return - V_67 ;
V_64 . type = F_21 ( V_46 ) ;
memset ( & V_64 . V_16 , 0xff , V_47 ) ;
memset ( V_30 , 0 , sizeof( V_30 ) ) ;
V_65 = F_30 ( V_46 , L_2 ,
F_15 , F_22 , F_1 ,
F_28 , & V_64 , V_68 ,
V_69 , V_70 ) ;
if ( V_65 )
return V_65 ;
V_71 . V_72 = & F_23 ;
V_71 . V_73 = 0 ;
V_65 = F_31 ( & V_71 ) ;
if ( ! V_65 )
V_66 = 1 ;
return V_65 ;
}
void F_32 ( void )
{
int V_74 ;
if ( ! V_66 )
return;
F_33 ( & V_71 ) ;
for ( V_74 = 0 ; V_74 < V_32 ; V_74 ++ ) {
if ( V_30 [ V_74 ] . V_25 ) {
V_30 [ V_74 ] . V_25 -> V_44 = 1 ;
V_30 [ V_74 ] . V_25 = NULL ;
}
if ( V_30 [ V_74 ] . V_9 ) {
F_34 ( & V_30 [ V_74 ] . V_40 ) ;
F_35 ( V_30 [ V_74 ] . V_9 ) ;
}
}
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_66 = 0 ;
}
