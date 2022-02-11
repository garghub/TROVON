static int F_1 ( struct V_1 * V_2 , unsigned int type )
{
return ( 1 << type ) & V_2 -> V_3 ;
}
static unsigned int F_2 ( struct V_1 * V_2 )
{
unsigned int V_4 ;
unsigned int V_5 = 0 ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
if ( F_1 ( V_2 , V_4 ) )
V_5 ++ ;
}
return V_5 ;
}
void F_3 ( struct V_1 * V_2 )
{
unsigned int V_7 = F_2 ( V_2 ) ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
memset ( V_2 -> V_8 [ V_4 ] . V_9 , 0 ,
V_2 -> V_8 [ V_4 ] . V_10 * sizeof( V_11 ) ) ;
}
}
int F_4 ( struct V_1 * V_12 , struct V_1 * V_13 )
{
return ( V_12 -> V_14 == V_13 -> V_14 ) ;
}
void F_5 ( struct V_1 * V_15 , struct V_1 * V_16 )
{
unsigned int V_4 ;
unsigned int V_17 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_15 ) ; V_4 ++ ) {
for ( V_17 = 0 ; V_17 < V_15 -> V_8 [ V_4 ] . V_10 ; V_17 ++ ) {
V_15 -> V_8 [ V_4 ] . V_9 [ V_17 ] +=
V_16 -> V_8 [ V_4 ] . V_9 [ V_17 ] ;
}
}
}
static T_1 F_6 ( struct V_1 * V_2 )
{
T_1 V_18 ;
V_18 = sizeof( struct V_19 ) + F_2 ( V_2 ) *
sizeof( unsigned int ) ;
if ( F_7 ( struct V_19 ) > sizeof( unsigned int ) )
V_18 = F_8 ( V_18 , F_7 ( struct V_19 ) ) ;
return V_18 ;
}
static struct V_19 * F_9 ( struct V_1 * V_2 , unsigned int V_20 )
{
return (struct V_19 * )
( ( char * ) V_2 -> V_21 + V_20 * F_6 ( V_2 ) ) ;
}
struct V_1 * F_10 ( struct V_1 * V_2 )
{
struct V_1 * V_22 ;
unsigned int V_4 ;
unsigned int V_7 ;
V_7 = F_2 ( V_2 ) ;
V_22 = F_11 ( sizeof( struct V_1 ) +
sizeof( struct V_23 ) * V_7 , V_24 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_25 = V_2 -> V_25 ;
V_22 -> V_14 = V_2 -> V_14 ;
V_22 -> V_26 = V_2 -> V_26 ;
V_22 -> V_3 = V_2 -> V_3 ;
V_22 -> V_27 = F_12 ( V_2 -> V_27 , V_24 ) ;
if ( ! V_22 -> V_27 )
goto V_28;
V_22 -> V_21 = F_13 ( V_2 -> V_21 , V_2 -> V_26 *
F_6 ( V_2 ) , V_24 ) ;
if ( ! V_22 -> V_21 )
goto V_28;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
struct V_23 * V_29 = & V_2 -> V_8 [ V_4 ] ;
T_1 V_18 = V_29 -> V_10 * sizeof( V_11 ) ;
V_22 -> V_8 [ V_4 ] . V_10 = V_29 -> V_10 ;
V_22 -> V_8 [ V_4 ] . V_30 = V_29 -> V_30 ;
V_22 -> V_8 [ V_4 ] . V_9 = F_14 ( V_18 ) ;
if ( ! V_22 -> V_8 [ V_4 ] . V_9 )
goto V_28;
memcpy ( V_22 -> V_8 [ V_4 ] . V_9 , V_29 -> V_9 , V_18 ) ;
}
return V_22 ;
V_28:
F_15 ( V_22 ) ;
return NULL ;
}
void F_15 ( struct V_1 * V_2 )
{
unsigned int V_7 = F_2 ( V_2 ) ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ )
F_16 ( V_2 -> V_8 [ V_4 ] . V_9 ) ;
F_17 ( V_2 -> V_21 ) ;
F_17 ( V_2 -> V_27 ) ;
F_17 ( V_2 ) ;
}
static struct V_19 * F_18 ( struct V_31 * V_32 )
{
return F_9 ( V_32 -> V_2 , V_32 -> V_33 ) ;
}
static struct V_34 * F_19 ( struct V_31 * V_32 )
{
return & V_32 -> V_34 [ V_32 -> type ] ;
}
struct V_31 * F_20 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
V_32 = F_11 ( sizeof( struct V_31 ) +
F_2 ( V_2 ) * sizeof( struct V_34 ) ,
V_24 ) ;
if ( V_32 )
V_32 -> V_2 = V_2 ;
return V_32 ;
}
void F_21 ( struct V_31 * V_32 )
{
F_17 ( V_32 ) ;
}
struct V_1 * F_22 ( struct V_31 * V_32 )
{
return V_32 -> V_2 ;
}
void F_23 ( struct V_31 * V_32 )
{
int V_4 ;
V_32 -> V_35 = 0 ;
V_32 -> V_33 = 0 ;
V_32 -> type = 0 ;
V_32 -> V_36 = 0 ;
V_32 -> V_37 = 0 ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
if ( F_1 ( V_32 -> V_2 , V_4 ) ) {
V_32 -> V_34 [ V_32 -> V_37 ] . V_38 = V_4 ;
V_32 -> V_34 [ V_32 -> V_37 ++ ] . V_39 = 0 ;
}
}
}
int F_24 ( struct V_31 * V_32 )
{
switch ( V_32 -> V_35 ) {
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
V_32 -> V_35 ++ ;
break;
case V_46 :
V_32 -> V_36 ++ ;
case V_47 :
if ( V_32 -> V_36 < F_18 ( V_32 ) -> V_48 [ V_32 -> type ] ) {
V_32 -> V_35 = 9 ;
break;
}
F_19 ( V_32 ) -> V_39 += V_32 -> V_36 ;
V_32 -> V_36 = 0 ;
V_32 -> type ++ ;
case V_49 :
if ( V_32 -> type < V_32 -> V_37 ) {
V_32 -> V_35 = 7 ;
break;
}
V_32 -> type = 0 ;
V_32 -> V_33 ++ ;
case V_50 :
if ( V_32 -> V_33 < V_32 -> V_2 -> V_26 )
V_32 -> V_35 = 3 ;
else
V_32 -> V_35 = - 1 ;
break;
}
if ( V_32 -> V_35 == - 1 )
return - V_51 ;
else
return 0 ;
}
static int F_25 ( struct V_52 * V_53 , T_2 V_54 )
{
return F_26 ( V_53 , & V_54 , sizeof( V_54 ) ) ;
}
static int F_27 ( struct V_52 * V_53 , T_3 V_54 )
{
T_2 V_55 [ 2 ] ;
V_55 [ 0 ] = ( V_54 & 0xffffffffUL ) ;
V_55 [ 1 ] = ( V_54 >> 32 ) ;
return F_26 ( V_53 , V_55 , sizeof( V_55 ) ) ;
}
int F_28 ( struct V_31 * V_32 , struct V_52 * V_53 )
{
int V_56 = - V_51 ;
switch ( V_32 -> V_35 ) {
case V_40 :
V_56 = F_25 ( V_53 , V_57 ) ;
break;
case V_41 :
V_56 = F_25 ( V_53 , V_32 -> V_2 -> V_25 ) ;
break;
case V_50 :
V_56 = F_25 ( V_53 , V_32 -> V_2 -> V_14 ) ;
break;
case V_42 :
V_56 = F_25 ( V_53 , V_58 ) ;
break;
case V_43 :
V_56 = F_25 ( V_53 , 2 ) ;
break;
case V_44 :
V_56 = F_25 ( V_53 , F_18 ( V_32 ) -> V_59 ) ;
break;
case V_49 :
V_56 = F_25 ( V_53 , F_18 ( V_32 ) -> V_60 ) ;
break;
case V_45 :
V_56 = F_25 ( V_53 ,
F_29 ( F_19 ( V_32 ) -> V_38 ) ) ;
break;
case V_47 :
V_56 = F_25 ( V_53 ,
F_18 ( V_32 ) -> V_48 [ V_32 -> type ] * 2 ) ;
break;
case V_46 :
V_56 = F_27 ( V_53 ,
V_32 -> V_2 -> V_8 [ V_32 -> type ] .
V_9 [ V_32 -> V_36 + F_19 ( V_32 ) -> V_39 ] ) ;
break;
}
return V_56 ;
}
