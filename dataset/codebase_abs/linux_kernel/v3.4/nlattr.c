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
const struct V_4 * V_5 )
{
const struct V_1 * V_2 ;
int V_24 , V_25 ;
F_9 (nla, head, len, rem) {
V_25 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_25 < 0 )
goto V_26;
}
V_25 = 0 ;
V_26:
return V_25 ;
}
int
F_10 ( const struct V_4 * V_27 , int V_28 )
{
int V_29 , V_13 = 0 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ , V_27 ++ ) {
if ( V_27 -> V_13 )
V_13 += F_11 ( V_27 -> V_13 ) ;
else if ( V_22 [ V_27 -> type ] )
V_13 += F_11 ( V_22 [ V_27 -> type ] ) ;
}
return V_13 ;
}
int F_12 ( struct V_1 * * V_30 , int V_3 , const struct V_1 * V_23 ,
int V_13 , const struct V_4 * V_5 )
{
const struct V_1 * V_2 ;
int V_24 , V_25 ;
memset ( V_30 , 0 , sizeof( struct V_1 * ) * ( V_3 + 1 ) ) ;
F_9 (nla, head, len, rem) {
T_1 type = F_3 ( V_2 ) ;
if ( type > 0 && type <= V_3 ) {
if ( V_5 ) {
V_25 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_25 < 0 )
goto V_26;
}
V_30 [ type ] = (struct V_1 * ) V_2 ;
}
}
if ( F_13 ( V_24 > 0 ) )
F_14 ( V_31 L_1
L_2 , V_24 ) ;
V_25 = 0 ;
V_26:
return V_25 ;
}
struct V_1 * F_15 ( const struct V_1 * V_23 , int V_13 , int V_32 )
{
const struct V_1 * V_2 ;
int V_24 ;
F_9 (nla, head, len, rem)
if ( F_3 ( V_2 ) == V_32 )
return (struct V_1 * ) V_2 ;
return NULL ;
}
T_2 F_16 ( char * V_33 , const struct V_1 * V_2 , T_2 V_34 )
{
T_2 V_35 = F_2 ( V_2 ) ;
char * V_36 = F_6 ( V_2 ) ;
if ( V_35 > 0 && V_36 [ V_35 - 1 ] == '\0' )
V_35 -- ;
if ( V_34 > 0 ) {
T_2 V_13 = ( V_35 >= V_34 ) ? V_34 - 1 : V_35 ;
memset ( V_33 , 0 , V_34 ) ;
memcpy ( V_33 , V_36 , V_13 ) ;
}
return V_35 ;
}
int F_17 ( void * V_37 , const struct V_1 * V_36 , int V_38 )
{
int V_7 = F_5 ( int , V_38 , F_2 ( V_36 ) ) ;
memcpy ( V_37 , F_6 ( V_36 ) , V_7 ) ;
return V_7 ;
}
int F_18 ( const struct V_1 * V_2 , const void * V_39 ,
T_2 V_40 )
{
int V_41 = F_2 ( V_2 ) - V_40 ;
if ( V_41 == 0 )
V_41 = memcmp ( F_6 ( V_2 ) , V_39 , V_40 ) ;
return V_41 ;
}
int F_19 ( const struct V_1 * V_2 , const char * V_42 )
{
int V_13 = strlen ( V_42 ) + 1 ;
int V_41 = F_2 ( V_2 ) - V_13 ;
if ( V_41 == 0 )
V_41 = memcmp ( F_6 ( V_2 ) , V_42 , V_13 ) ;
return V_41 ;
}
struct V_1 * F_20 ( struct V_43 * V_44 , int V_32 , int V_8 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_21 ( V_44 , F_11 ( V_8 ) ) ;
V_2 -> F_3 = V_32 ;
V_2 -> F_2 = F_22 ( V_8 ) ;
memset ( ( unsigned char * ) V_2 + V_2 -> F_2 , 0 , F_23 ( V_8 ) ) ;
return V_2 ;
}
void * F_24 ( struct V_43 * V_44 , int V_8 )
{
void * V_45 ;
V_45 = F_21 ( V_44 , F_7 ( V_8 ) ) ;
memset ( V_45 , 0 , F_7 ( V_8 ) ) ;
return V_45 ;
}
struct V_1 * F_25 ( struct V_43 * V_44 , int V_32 , int V_8 )
{
if ( F_13 ( F_26 ( V_44 ) < F_11 ( V_8 ) ) )
return NULL ;
return F_20 ( V_44 , V_32 , V_8 ) ;
}
void * F_27 ( struct V_43 * V_44 , int V_8 )
{
if ( F_13 ( F_26 ( V_44 ) < F_7 ( V_8 ) ) )
return NULL ;
return F_24 ( V_44 , V_8 ) ;
}
void F_28 ( struct V_43 * V_44 , int V_32 , int V_8 ,
const void * V_39 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_44 , V_32 , V_8 ) ;
memcpy ( F_6 ( V_2 ) , V_39 , V_8 ) ;
}
void F_29 ( struct V_43 * V_44 , int V_8 , const void * V_39 )
{
void * V_45 ;
V_45 = F_24 ( V_44 , V_8 ) ;
memcpy ( V_45 , V_39 , V_8 ) ;
}
int F_30 ( struct V_43 * V_44 , int V_32 , int V_8 , const void * V_39 )
{
if ( F_13 ( F_26 ( V_44 ) < F_11 ( V_8 ) ) )
return - V_46 ;
F_28 ( V_44 , V_32 , V_8 , V_39 ) ;
return 0 ;
}
int F_31 ( struct V_43 * V_44 , int V_8 , const void * V_39 )
{
if ( F_13 ( F_26 ( V_44 ) < F_7 ( V_8 ) ) )
return - V_46 ;
F_29 ( V_44 , V_8 , V_39 ) ;
return 0 ;
}
int F_32 ( struct V_43 * V_44 , int V_8 , const void * V_39 )
{
if ( F_13 ( F_26 ( V_44 ) < F_7 ( V_8 ) ) )
return - V_46 ;
memcpy ( F_21 ( V_44 , V_8 ) , V_39 , V_8 ) ;
return 0 ;
}
