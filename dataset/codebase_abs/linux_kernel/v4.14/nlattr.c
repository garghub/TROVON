static int F_1 ( const struct V_1 * V_2 ,
T_1 * V_3 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 * V_6 = V_3 ;
if ( ! V_3 )
return - V_7 ;
if ( V_5 -> V_8 & ~ * V_6 )
return - V_7 ;
if ( V_5 -> V_9 & ~ * V_6 )
return - V_7 ;
if ( V_5 -> V_9 & ~ V_5 -> V_8 )
return - V_7 ;
return 0 ;
}
static int F_3 ( const struct V_1 * V_2 , int V_10 ,
const struct V_11 * V_12 )
{
const struct V_11 * V_13 ;
int V_14 = 0 , V_15 = F_4 ( V_2 ) , type = F_5 ( V_2 ) ;
if ( type <= 0 || type > V_10 )
return 0 ;
V_13 = & V_12 [ type ] ;
F_6 ( V_13 -> type > V_16 ) ;
switch ( V_13 -> type ) {
case V_17 :
if ( V_15 > 0 )
return - V_18 ;
break;
case V_19 :
if ( V_15 != sizeof( struct V_4 ) )
return - V_18 ;
return F_1 ( V_2 , V_13 -> V_20 ) ;
case V_21 :
if ( V_13 -> V_22 )
V_14 = F_7 ( int , V_15 , V_13 -> V_22 + 1 ) ;
else
V_14 = V_15 ;
if ( ! V_14 || memchr ( F_2 ( V_2 ) , '\0' , V_14 ) == NULL )
return - V_7 ;
case V_23 :
if ( V_15 < 1 )
return - V_18 ;
if ( V_13 -> V_22 ) {
char * V_24 = F_2 ( V_2 ) ;
if ( V_24 [ V_15 - 1 ] == '\0' )
V_15 -- ;
if ( V_15 > V_13 -> V_22 )
return - V_18 ;
}
break;
case V_25 :
if ( V_13 -> V_22 && V_15 > V_13 -> V_22 )
return - V_18 ;
break;
case V_26 :
if ( V_15 < V_13 -> V_22 )
return - V_18 ;
if ( V_15 < F_8 ( V_13 -> V_22 ) )
break;
if ( V_15 < F_8 ( V_13 -> V_22 ) + V_27 )
return - V_18 ;
V_2 = F_2 ( V_2 ) + F_8 ( V_13 -> V_22 ) ;
if ( V_15 < F_8 ( V_13 -> V_22 ) + V_27 + F_4 ( V_2 ) )
return - V_18 ;
break;
case V_28 :
if ( V_15 == 0 )
break;
default:
if ( V_13 -> V_22 )
V_14 = V_13 -> V_22 ;
else if ( V_13 -> type != V_29 )
V_14 = V_30 [ V_13 -> type ] ;
if ( V_15 < V_14 )
return - V_18 ;
}
return 0 ;
}
int F_9 ( const struct V_1 * V_31 , int V_22 , int V_10 ,
const struct V_11 * V_12 ,
struct V_32 * V_33 )
{
const struct V_1 * V_2 ;
int V_34 ;
F_10 (nla, head, len, rem) {
int V_35 = F_3 ( V_2 , V_10 , V_12 ) ;
if ( V_35 < 0 ) {
if ( V_33 )
V_33 -> V_36 = V_2 ;
return V_35 ;
}
}
return 0 ;
}
int
F_11 ( const struct V_11 * V_37 , int V_38 )
{
int V_39 , V_22 = 0 ;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ , V_37 ++ ) {
if ( V_37 -> V_22 )
V_22 += F_12 ( V_37 -> V_22 ) ;
else if ( V_30 [ V_37 -> type ] )
V_22 += F_12 ( V_30 [ V_37 -> type ] ) ;
}
return V_22 ;
}
int F_13 ( struct V_1 * * V_40 , int V_10 , const struct V_1 * V_31 ,
int V_22 , const struct V_11 * V_12 ,
struct V_32 * V_33 )
{
const struct V_1 * V_2 ;
int V_34 , V_35 ;
memset ( V_40 , 0 , sizeof( struct V_1 * ) * ( V_10 + 1 ) ) ;
F_10 (nla, head, len, rem) {
T_2 type = F_5 ( V_2 ) ;
if ( type > 0 && type <= V_10 ) {
if ( V_12 ) {
V_35 = F_3 ( V_2 , V_10 , V_12 ) ;
if ( V_35 < 0 ) {
if ( V_33 )
V_33 -> V_36 = V_2 ;
goto V_41;
}
}
V_40 [ type ] = (struct V_1 * ) V_2 ;
}
}
if ( F_14 ( V_34 > 0 ) )
F_15 ( L_1 ,
V_34 , V_42 -> V_43 ) ;
V_35 = 0 ;
V_41:
return V_35 ;
}
struct V_1 * F_16 ( const struct V_1 * V_31 , int V_22 , int V_44 )
{
const struct V_1 * V_2 ;
int V_34 ;
F_10 (nla, head, len, rem)
if ( F_5 ( V_2 ) == V_44 )
return (struct V_1 * ) V_2 ;
return NULL ;
}
T_3 F_17 ( char * V_45 , const struct V_1 * V_2 , T_3 V_46 )
{
T_3 V_47 = F_4 ( V_2 ) ;
char * V_48 = F_2 ( V_2 ) ;
if ( V_47 > 0 && V_48 [ V_47 - 1 ] == '\0' )
V_47 -- ;
if ( V_46 > 0 ) {
T_3 V_22 = ( V_47 >= V_46 ) ? V_46 - 1 : V_47 ;
memset ( V_45 , 0 , V_46 ) ;
memcpy ( V_45 , V_48 , V_22 ) ;
}
return V_47 ;
}
char * F_18 ( const struct V_1 * V_2 , T_4 V_49 )
{
T_3 V_47 = F_4 ( V_2 ) ;
char * V_48 = F_2 ( V_2 ) , * V_45 ;
if ( V_47 > 0 && V_48 [ V_47 - 1 ] == '\0' )
V_47 -- ;
V_45 = F_19 ( V_47 + 1 , V_49 ) ;
if ( V_45 != NULL ) {
memcpy ( V_45 , V_48 , V_47 ) ;
V_45 [ V_47 ] = '\0' ;
}
return V_45 ;
}
int F_20 ( void * V_50 , const struct V_1 * V_48 , int V_51 )
{
int V_14 = F_7 ( int , V_51 , F_4 ( V_48 ) ) ;
memcpy ( V_50 , F_2 ( V_48 ) , V_14 ) ;
if ( V_51 > V_14 )
memset ( V_50 + V_14 , 0 , V_51 - V_14 ) ;
return V_14 ;
}
int F_21 ( const struct V_1 * V_2 , const void * V_52 ,
T_3 V_53 )
{
int V_54 = F_4 ( V_2 ) - V_53 ;
if ( V_54 == 0 )
V_54 = memcmp ( F_2 ( V_2 ) , V_52 , V_53 ) ;
return V_54 ;
}
int F_22 ( const struct V_1 * V_2 , const char * V_55 )
{
int V_22 = strlen ( V_55 ) ;
char * V_24 = F_2 ( V_2 ) ;
int V_15 = F_4 ( V_2 ) ;
int V_54 ;
if ( V_15 > 0 && V_24 [ V_15 - 1 ] == '\0' )
V_15 -- ;
V_54 = V_15 - V_22 ;
if ( V_54 == 0 )
V_54 = memcmp ( F_2 ( V_2 ) , V_55 , V_22 ) ;
return V_54 ;
}
struct V_1 * F_23 ( struct V_56 * V_57 , int V_44 , int V_15 )
{
struct V_1 * V_2 ;
V_2 = F_24 ( V_57 , F_12 ( V_15 ) ) ;
V_2 -> F_5 = V_44 ;
V_2 -> F_4 = F_25 ( V_15 ) ;
memset ( ( unsigned char * ) V_2 + V_2 -> F_4 , 0 , F_26 ( V_15 ) ) ;
return V_2 ;
}
struct V_1 * F_27 ( struct V_56 * V_57 , int V_44 ,
int V_15 , int V_58 )
{
if ( F_28 ( V_57 ) )
F_29 ( V_57 , V_58 ) ;
return F_23 ( V_57 , V_44 , V_15 ) ;
}
void * F_30 ( struct V_56 * V_57 , int V_15 )
{
return F_31 ( V_57 , F_8 ( V_15 ) ) ;
}
struct V_1 * F_32 ( struct V_56 * V_57 , int V_44 , int V_15 )
{
if ( F_14 ( F_33 ( V_57 ) < F_12 ( V_15 ) ) )
return NULL ;
return F_23 ( V_57 , V_44 , V_15 ) ;
}
struct V_1 * F_34 ( struct V_56 * V_57 , int V_44 , int V_15 ,
int V_58 )
{
T_3 V_22 ;
if ( F_28 ( V_57 ) )
V_22 = F_35 ( V_15 ) ;
else
V_22 = F_12 ( V_15 ) ;
if ( F_14 ( F_33 ( V_57 ) < V_22 ) )
return NULL ;
return F_27 ( V_57 , V_44 , V_15 , V_58 ) ;
}
void * F_36 ( struct V_56 * V_57 , int V_15 )
{
if ( F_14 ( F_33 ( V_57 ) < F_8 ( V_15 ) ) )
return NULL ;
return F_30 ( V_57 , V_15 ) ;
}
void F_37 ( struct V_56 * V_57 , int V_44 , int V_15 ,
const void * V_52 )
{
struct V_1 * V_2 ;
V_2 = F_23 ( V_57 , V_44 , V_15 ) ;
memcpy ( F_2 ( V_2 ) , V_52 , V_15 ) ;
}
void F_38 ( struct V_56 * V_57 , int V_44 , int V_15 ,
const void * V_52 , int V_58 )
{
struct V_1 * V_2 ;
V_2 = F_27 ( V_57 , V_44 , V_15 , V_58 ) ;
memcpy ( F_2 ( V_2 ) , V_52 , V_15 ) ;
}
void F_39 ( struct V_56 * V_57 , int V_15 , const void * V_52 )
{
void * V_59 ;
V_59 = F_30 ( V_57 , V_15 ) ;
memcpy ( V_59 , V_52 , V_15 ) ;
}
int F_40 ( struct V_56 * V_57 , int V_44 , int V_15 , const void * V_52 )
{
if ( F_14 ( F_33 ( V_57 ) < F_12 ( V_15 ) ) )
return - V_60 ;
F_37 ( V_57 , V_44 , V_15 , V_52 ) ;
return 0 ;
}
int F_41 ( struct V_56 * V_57 , int V_44 , int V_15 ,
const void * V_52 , int V_58 )
{
T_3 V_22 ;
if ( F_28 ( V_57 ) )
V_22 = F_35 ( V_15 ) ;
else
V_22 = F_12 ( V_15 ) ;
if ( F_14 ( F_33 ( V_57 ) < V_22 ) )
return - V_60 ;
F_38 ( V_57 , V_44 , V_15 , V_52 , V_58 ) ;
return 0 ;
}
int F_42 ( struct V_56 * V_57 , int V_15 , const void * V_52 )
{
if ( F_14 ( F_33 ( V_57 ) < F_8 ( V_15 ) ) )
return - V_60 ;
F_39 ( V_57 , V_15 , V_52 ) ;
return 0 ;
}
int F_43 ( struct V_56 * V_57 , int V_15 , const void * V_52 )
{
if ( F_14 ( F_33 ( V_57 ) < F_8 ( V_15 ) ) )
return - V_60 ;
F_44 ( V_57 , V_52 , V_15 ) ;
return 0 ;
}
