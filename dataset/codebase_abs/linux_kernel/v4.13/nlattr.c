static int F_1 ( const struct V_1 * V_2 , int V_3 ,
const struct V_4 * V_5 )
{
const struct V_4 * V_6 ;
int V_7 = 0 , V_8 = F_2 ( V_2 ) , type = F_3 ( V_2 ) ;
if ( type <= 0 || type > V_3 )
return 0 ;
V_6 = & V_5 [ type ] ;
F_4 ( V_6 -> type > V_9 ) ;
switch ( V_6 -> type ) {
case V_10 :
if ( V_8 > 0 )
return - V_11 ;
break;
case V_12 :
if ( V_6 -> V_13 )
V_7 = F_5 ( int , V_8 , V_6 -> V_13 + 1 ) ;
else
V_7 = V_8 ;
if ( ! V_7 || memchr ( F_6 ( V_2 ) , '\0' , V_7 ) == NULL )
return - V_14 ;
case V_15 :
if ( V_8 < 1 )
return - V_11 ;
if ( V_6 -> V_13 ) {
char * V_16 = F_6 ( V_2 ) ;
if ( V_16 [ V_8 - 1 ] == '\0' )
V_8 -- ;
if ( V_8 > V_6 -> V_13 )
return - V_11 ;
}
break;
case V_17 :
if ( V_6 -> V_13 && V_8 > V_6 -> V_13 )
return - V_11 ;
break;
case V_18 :
if ( V_8 < V_6 -> V_13 )
return - V_11 ;
if ( V_8 < F_7 ( V_6 -> V_13 ) )
break;
if ( V_8 < F_7 ( V_6 -> V_13 ) + V_19 )
return - V_11 ;
V_2 = F_6 ( V_2 ) + F_7 ( V_6 -> V_13 ) ;
if ( V_8 < F_7 ( V_6 -> V_13 ) + V_19 + F_2 ( V_2 ) )
return - V_11 ;
break;
case V_20 :
if ( V_8 == 0 )
break;
default:
if ( V_6 -> V_13 )
V_7 = V_6 -> V_13 ;
else if ( V_6 -> type != V_21 )
V_7 = V_22 [ V_6 -> type ] ;
if ( V_8 < V_7 )
return - V_11 ;
}
return 0 ;
}
int F_8 ( const struct V_1 * V_23 , int V_13 , int V_3 ,
const struct V_4 * V_5 ,
struct V_24 * V_25 )
{
const struct V_1 * V_2 ;
int V_26 ;
F_9 (nla, head, len, rem) {
int V_27 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_27 < 0 ) {
if ( V_25 )
V_25 -> V_28 = V_2 ;
return V_27 ;
}
}
return 0 ;
}
int
F_10 ( const struct V_4 * V_29 , int V_30 )
{
int V_31 , V_13 = 0 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ , V_29 ++ ) {
if ( V_29 -> V_13 )
V_13 += F_11 ( V_29 -> V_13 ) ;
else if ( V_22 [ V_29 -> type ] )
V_13 += F_11 ( V_22 [ V_29 -> type ] ) ;
}
return V_13 ;
}
int F_12 ( struct V_1 * * V_32 , int V_3 , const struct V_1 * V_23 ,
int V_13 , const struct V_4 * V_5 ,
struct V_24 * V_25 )
{
const struct V_1 * V_2 ;
int V_26 , V_27 ;
memset ( V_32 , 0 , sizeof( struct V_1 * ) * ( V_3 + 1 ) ) ;
F_9 (nla, head, len, rem) {
T_1 type = F_3 ( V_2 ) ;
if ( type > 0 && type <= V_3 ) {
if ( V_5 ) {
V_27 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_27 < 0 ) {
if ( V_25 )
V_25 -> V_28 = V_2 ;
goto V_33;
}
}
V_32 [ type ] = (struct V_1 * ) V_2 ;
}
}
if ( F_13 ( V_26 > 0 ) )
F_14 ( L_1 ,
V_26 , V_34 -> V_35 ) ;
V_27 = 0 ;
V_33:
return V_27 ;
}
struct V_1 * F_15 ( const struct V_1 * V_23 , int V_13 , int V_36 )
{
const struct V_1 * V_2 ;
int V_26 ;
F_9 (nla, head, len, rem)
if ( F_3 ( V_2 ) == V_36 )
return (struct V_1 * ) V_2 ;
return NULL ;
}
T_2 F_16 ( char * V_37 , const struct V_1 * V_2 , T_2 V_38 )
{
T_2 V_39 = F_2 ( V_2 ) ;
char * V_40 = F_6 ( V_2 ) ;
if ( V_39 > 0 && V_40 [ V_39 - 1 ] == '\0' )
V_39 -- ;
if ( V_38 > 0 ) {
T_2 V_13 = ( V_39 >= V_38 ) ? V_38 - 1 : V_39 ;
memset ( V_37 , 0 , V_38 ) ;
memcpy ( V_37 , V_40 , V_13 ) ;
}
return V_39 ;
}
int F_17 ( void * V_41 , const struct V_1 * V_40 , int V_42 )
{
int V_7 = F_5 ( int , V_42 , F_2 ( V_40 ) ) ;
memcpy ( V_41 , F_6 ( V_40 ) , V_7 ) ;
if ( V_42 > V_7 )
memset ( V_41 + V_7 , 0 , V_42 - V_7 ) ;
return V_7 ;
}
int F_18 ( const struct V_1 * V_2 , const void * V_43 ,
T_2 V_44 )
{
int V_45 = F_2 ( V_2 ) - V_44 ;
if ( V_45 == 0 )
V_45 = memcmp ( F_6 ( V_2 ) , V_43 , V_44 ) ;
return V_45 ;
}
int F_19 ( const struct V_1 * V_2 , const char * V_46 )
{
int V_13 = strlen ( V_46 ) ;
char * V_16 = F_6 ( V_2 ) ;
int V_8 = F_2 ( V_2 ) ;
int V_45 ;
if ( V_8 > 0 && V_16 [ V_8 - 1 ] == '\0' )
V_8 -- ;
V_45 = V_8 - V_13 ;
if ( V_45 == 0 )
V_45 = memcmp ( F_6 ( V_2 ) , V_46 , V_13 ) ;
return V_45 ;
}
struct V_1 * F_20 ( struct V_47 * V_48 , int V_36 , int V_8 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_48 , F_11 ( V_8 ) ) ;
V_2 -> F_3 = V_36 ;
V_2 -> F_2 = F_22 ( V_8 ) ;
memset ( ( unsigned char * ) V_2 + V_2 -> F_2 , 0 , F_23 ( V_8 ) ) ;
return V_2 ;
}
struct V_1 * F_24 ( struct V_47 * V_48 , int V_36 ,
int V_8 , int V_49 )
{
if ( F_25 ( V_48 ) )
F_26 ( V_48 , V_49 ) ;
return F_20 ( V_48 , V_36 , V_8 ) ;
}
void * F_27 ( struct V_47 * V_48 , int V_8 )
{
return F_28 ( V_48 , F_7 ( V_8 ) ) ;
}
struct V_1 * F_29 ( struct V_47 * V_48 , int V_36 , int V_8 )
{
if ( F_13 ( F_30 ( V_48 ) < F_11 ( V_8 ) ) )
return NULL ;
return F_20 ( V_48 , V_36 , V_8 ) ;
}
struct V_1 * F_31 ( struct V_47 * V_48 , int V_36 , int V_8 ,
int V_49 )
{
T_2 V_13 ;
if ( F_25 ( V_48 ) )
V_13 = F_32 ( V_8 ) ;
else
V_13 = F_11 ( V_8 ) ;
if ( F_13 ( F_30 ( V_48 ) < V_13 ) )
return NULL ;
return F_24 ( V_48 , V_36 , V_8 , V_49 ) ;
}
void * F_33 ( struct V_47 * V_48 , int V_8 )
{
if ( F_13 ( F_30 ( V_48 ) < F_7 ( V_8 ) ) )
return NULL ;
return F_27 ( V_48 , V_8 ) ;
}
void F_34 ( struct V_47 * V_48 , int V_36 , int V_8 ,
const void * V_43 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_48 , V_36 , V_8 ) ;
memcpy ( F_6 ( V_2 ) , V_43 , V_8 ) ;
}
void F_35 ( struct V_47 * V_48 , int V_36 , int V_8 ,
const void * V_43 , int V_49 )
{
struct V_1 * V_2 ;
V_2 = F_24 ( V_48 , V_36 , V_8 , V_49 ) ;
memcpy ( F_6 ( V_2 ) , V_43 , V_8 ) ;
}
void F_36 ( struct V_47 * V_48 , int V_8 , const void * V_43 )
{
void * V_50 ;
V_50 = F_27 ( V_48 , V_8 ) ;
memcpy ( V_50 , V_43 , V_8 ) ;
}
int F_37 ( struct V_47 * V_48 , int V_36 , int V_8 , const void * V_43 )
{
if ( F_13 ( F_30 ( V_48 ) < F_11 ( V_8 ) ) )
return - V_51 ;
F_34 ( V_48 , V_36 , V_8 , V_43 ) ;
return 0 ;
}
int F_38 ( struct V_47 * V_48 , int V_36 , int V_8 ,
const void * V_43 , int V_49 )
{
T_2 V_13 ;
if ( F_25 ( V_48 ) )
V_13 = F_32 ( V_8 ) ;
else
V_13 = F_11 ( V_8 ) ;
if ( F_13 ( F_30 ( V_48 ) < V_13 ) )
return - V_51 ;
F_35 ( V_48 , V_36 , V_8 , V_43 , V_49 ) ;
return 0 ;
}
int F_39 ( struct V_47 * V_48 , int V_8 , const void * V_43 )
{
if ( F_13 ( F_30 ( V_48 ) < F_7 ( V_8 ) ) )
return - V_51 ;
F_36 ( V_48 , V_8 , V_43 ) ;
return 0 ;
}
int F_40 ( struct V_47 * V_48 , int V_8 , const void * V_43 )
{
if ( F_13 ( F_30 ( V_48 ) < F_7 ( V_8 ) ) )
return - V_51 ;
F_41 ( V_48 , V_43 , V_8 ) ;
return 0 ;
}
