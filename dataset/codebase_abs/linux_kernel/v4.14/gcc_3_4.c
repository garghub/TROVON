const char * F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
unsigned int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_4 ;
}
struct V_1 * F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return V_5 ;
return V_2 -> V_6 ;
}
void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_6 = V_5 ;
V_5 = V_2 ;
}
void F_5 ( struct V_1 * V_7 , struct V_1 * V_2 )
{
if ( V_7 )
V_7 -> V_6 = V_2 -> V_6 ;
else
V_5 = V_2 -> V_6 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int type )
{
return ( 1 << type ) & V_2 -> V_8 ;
}
static unsigned int F_7 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
unsigned int V_10 = 0 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
if ( F_6 ( V_2 , V_9 ) )
V_10 ++ ;
}
return V_10 ;
}
void F_8 ( struct V_1 * V_2 )
{
unsigned int V_12 = F_7 ( V_2 ) ;
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
memset ( V_2 -> V_13 [ V_9 ] . V_14 , 0 ,
V_2 -> V_13 [ V_9 ] . V_15 * sizeof( V_16 ) ) ;
}
}
int F_9 ( struct V_1 * V_17 , struct V_1 * V_18 )
{
return ( V_17 -> V_19 == V_18 -> V_19 ) ;
}
void F_10 ( struct V_1 * V_20 , struct V_1 * V_21 )
{
unsigned int V_9 ;
unsigned int V_22 ;
for ( V_9 = 0 ; V_9 < F_7 ( V_20 ) ; V_9 ++ ) {
for ( V_22 = 0 ; V_22 < V_20 -> V_13 [ V_9 ] . V_15 ; V_22 ++ ) {
V_20 -> V_13 [ V_9 ] . V_14 [ V_22 ] +=
V_21 -> V_13 [ V_9 ] . V_14 [ V_22 ] ;
}
}
}
static T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_23 ;
V_23 = sizeof( struct V_24 ) + F_7 ( V_2 ) *
sizeof( unsigned int ) ;
if ( F_12 ( struct V_24 ) > sizeof( unsigned int ) )
V_23 = F_13 ( V_23 , F_12 ( struct V_24 ) ) ;
return V_23 ;
}
static struct V_24 * F_14 ( struct V_1 * V_2 , unsigned int V_25 )
{
return (struct V_24 * )
( ( char * ) V_2 -> V_26 + V_25 * F_11 ( V_2 ) ) ;
}
struct V_1 * F_15 ( struct V_1 * V_2 )
{
struct V_1 * V_27 ;
unsigned int V_9 ;
unsigned int V_12 ;
V_12 = F_7 ( V_2 ) ;
V_27 = F_16 ( sizeof( struct V_1 ) +
sizeof( struct V_28 ) * V_12 , V_29 ) ;
if ( ! V_27 )
return NULL ;
V_27 -> V_4 = V_2 -> V_4 ;
V_27 -> V_19 = V_2 -> V_19 ;
V_27 -> V_30 = V_2 -> V_30 ;
V_27 -> V_8 = V_2 -> V_8 ;
V_27 -> V_3 = F_17 ( V_2 -> V_3 , V_29 ) ;
if ( ! V_27 -> V_3 )
goto V_31;
V_27 -> V_26 = F_18 ( V_2 -> V_26 , V_2 -> V_30 *
F_11 ( V_2 ) , V_29 ) ;
if ( ! V_27 -> V_26 )
goto V_31;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
struct V_28 * V_32 = & V_2 -> V_13 [ V_9 ] ;
T_1 V_23 = V_32 -> V_15 * sizeof( V_16 ) ;
V_27 -> V_13 [ V_9 ] . V_15 = V_32 -> V_15 ;
V_27 -> V_13 [ V_9 ] . V_33 = V_32 -> V_33 ;
V_27 -> V_13 [ V_9 ] . V_14 = F_19 ( V_23 ) ;
if ( ! V_27 -> V_13 [ V_9 ] . V_14 )
goto V_31;
memcpy ( V_27 -> V_13 [ V_9 ] . V_14 , V_32 -> V_14 , V_23 ) ;
}
return V_27 ;
V_31:
F_20 ( V_27 ) ;
return NULL ;
}
void F_20 ( struct V_1 * V_2 )
{
unsigned int V_12 = F_7 ( V_2 ) ;
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
F_21 ( V_2 -> V_13 [ V_9 ] . V_14 ) ;
F_22 ( V_2 -> V_26 ) ;
F_22 ( V_2 -> V_3 ) ;
F_22 ( V_2 ) ;
}
static struct V_24 * F_23 ( struct V_34 * V_35 )
{
return F_14 ( V_35 -> V_2 , V_35 -> V_36 ) ;
}
static struct V_37 * F_24 ( struct V_34 * V_35 )
{
return & V_35 -> V_37 [ V_35 -> type ] ;
}
struct V_34 * F_25 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
V_35 = F_16 ( sizeof( struct V_34 ) +
F_7 ( V_2 ) * sizeof( struct V_37 ) ,
V_29 ) ;
if ( V_35 )
V_35 -> V_2 = V_2 ;
return V_35 ;
}
void F_26 ( struct V_34 * V_35 )
{
F_22 ( V_35 ) ;
}
struct V_1 * F_27 ( struct V_34 * V_35 )
{
return V_35 -> V_2 ;
}
void F_28 ( struct V_34 * V_35 )
{
int V_9 ;
V_35 -> V_38 = 0 ;
V_35 -> V_36 = 0 ;
V_35 -> type = 0 ;
V_35 -> V_39 = 0 ;
V_35 -> V_40 = 0 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
if ( F_6 ( V_35 -> V_2 , V_9 ) ) {
V_35 -> V_37 [ V_35 -> V_40 ] . V_41 = V_9 ;
V_35 -> V_37 [ V_35 -> V_40 ++ ] . V_42 = 0 ;
}
}
}
int F_29 ( struct V_34 * V_35 )
{
switch ( V_35 -> V_38 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
V_35 -> V_38 ++ ;
break;
case V_49 :
V_35 -> V_39 ++ ;
case V_50 :
if ( V_35 -> V_39 < F_23 ( V_35 ) -> V_51 [ V_35 -> type ] ) {
V_35 -> V_38 = 9 ;
break;
}
F_24 ( V_35 ) -> V_42 += V_35 -> V_39 ;
V_35 -> V_39 = 0 ;
V_35 -> type ++ ;
case V_52 :
if ( V_35 -> type < V_35 -> V_40 ) {
V_35 -> V_38 = 7 ;
break;
}
V_35 -> type = 0 ;
V_35 -> V_36 ++ ;
case V_53 :
if ( V_35 -> V_36 < V_35 -> V_2 -> V_30 )
V_35 -> V_38 = 3 ;
else
V_35 -> V_38 = - 1 ;
break;
}
if ( V_35 -> V_38 == - 1 )
return - V_54 ;
else
return 0 ;
}
static int F_30 ( struct V_55 * V_56 , T_2 V_57 )
{
return F_31 ( V_56 , & V_57 , sizeof( V_57 ) ) ;
}
static int F_32 ( struct V_55 * V_56 , T_3 V_57 )
{
T_2 V_58 [ 2 ] ;
V_58 [ 0 ] = ( V_57 & 0xffffffffUL ) ;
V_58 [ 1 ] = ( V_57 >> 32 ) ;
return F_31 ( V_56 , V_58 , sizeof( V_58 ) ) ;
}
int F_33 ( struct V_34 * V_35 , struct V_55 * V_56 )
{
int V_59 = - V_54 ;
switch ( V_35 -> V_38 ) {
case V_43 :
V_59 = F_30 ( V_56 , V_60 ) ;
break;
case V_44 :
V_59 = F_30 ( V_56 , V_35 -> V_2 -> V_4 ) ;
break;
case V_53 :
V_59 = F_30 ( V_56 , V_35 -> V_2 -> V_19 ) ;
break;
case V_45 :
V_59 = F_30 ( V_56 , V_61 ) ;
break;
case V_46 :
V_59 = F_30 ( V_56 , 2 ) ;
break;
case V_47 :
V_59 = F_30 ( V_56 , F_23 ( V_35 ) -> V_62 ) ;
break;
case V_52 :
V_59 = F_30 ( V_56 , F_23 ( V_35 ) -> V_63 ) ;
break;
case V_48 :
V_59 = F_30 ( V_56 ,
F_34 ( F_24 ( V_35 ) -> V_41 ) ) ;
break;
case V_50 :
V_59 = F_30 ( V_56 ,
F_23 ( V_35 ) -> V_51 [ V_35 -> type ] * 2 ) ;
break;
case V_49 :
V_59 = F_32 ( V_56 ,
V_35 -> V_2 -> V_13 [ V_35 -> type ] .
V_14 [ V_35 -> V_39 + F_24 ( V_35 ) -> V_42 ] ) ;
break;
}
return V_59 ;
}
