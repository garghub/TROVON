static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( L_1 , V_2 ) ;
V_4 = F_3 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return - V_6 ;
F_4 ( & V_4 -> V_7 ) ;
V_2 -> V_8 = V_4 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_2 ( L_1 , V_2 ) ;
F_6 ( & V_4 -> V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
V_2 -> V_8 = NULL ;
F_2 ( L_1 , V_2 ) ;
F_6 ( & V_4 -> V_7 ) ;
F_8 ( V_4 -> V_9 ) ;
V_2 -> V_8 = NULL ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_2 ( L_2 , V_2 , V_11 ) ;
memcpy ( F_11 ( V_11 , 1 ) , & F_12 ( V_11 ) , 1 ) ;
F_13 ( & V_4 -> V_7 , V_11 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , const void * V_12 , int V_13 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
if ( ! F_15 ( V_14 , & V_2 -> V_15 ) )
return - V_16 ;
V_4 -> V_9 = F_16 ( V_2 -> V_17 , V_4 -> V_9 , V_12 , V_13 ,
V_18 , F_17 ( V_18 ) ) ;
if ( F_18 ( V_4 -> V_9 ) ) {
int V_19 = F_19 ( V_4 -> V_9 ) ;
F_20 ( L_3 , V_2 -> V_17 -> V_20 , V_19 ) ;
V_4 -> V_9 = NULL ;
return V_19 ;
}
return V_13 ;
}
static struct V_10 * F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
return F_22 ( & V_4 -> V_7 ) ;
}
int T_1 F_23 ( void )
{
return F_24 ( & V_21 ) ;
}
int T_2 F_25 ( void )
{
return F_26 ( & V_21 ) ;
}
struct V_10 * F_16 ( struct V_22 * V_17 , struct V_10 * V_11 ,
const unsigned char * V_23 , int V_13 ,
const struct V_24 * V_25 , int V_26 )
{
while ( V_13 ) {
int V_27 , V_28 ;
if ( ! V_11 ) {
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
if ( V_23 [ 0 ] != ( & V_25 [ V_27 ] ) -> type )
continue;
V_11 = F_27 ( ( & V_25 [ V_27 ] ) -> V_29 ,
V_30 ) ;
if ( ! V_11 )
return F_28 ( - V_6 ) ;
F_12 ( V_11 ) = ( & V_25 [ V_27 ] ) -> type ;
F_29 ( V_11 ) = ( & V_25 [ V_27 ] ) -> V_31 ;
break;
}
if ( ! V_11 )
return F_28 ( - V_32 ) ;
V_13 -= 1 ;
V_23 += 1 ;
}
V_28 = F_30 ( V_33 , F_29 ( V_11 ) - V_11 -> V_28 , V_13 ) ;
memcpy ( F_31 ( V_11 , V_28 ) , V_23 , V_28 ) ;
V_13 -= V_28 ;
V_23 += V_28 ;
if ( V_11 -> V_28 < F_29 ( V_11 ) )
continue;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
if ( F_12 ( V_11 ) == ( & V_25 [ V_27 ] ) -> type )
break;
}
if ( V_27 >= V_26 ) {
F_8 ( V_11 ) ;
return F_28 ( - V_32 ) ;
}
if ( V_11 -> V_28 == ( & V_25 [ V_27 ] ) -> V_31 ) {
T_3 V_34 ;
switch ( ( & V_25 [ V_27 ] ) -> V_35 ) {
case 0 :
V_34 = 0 ;
break;
case 1 :
V_34 = V_11 -> V_12 [ ( & V_25 [ V_27 ] ) -> V_36 ] ;
F_29 ( V_11 ) += V_34 ;
if ( F_32 ( V_11 ) < V_34 ) {
F_8 ( V_11 ) ;
return F_28 ( - V_37 ) ;
}
break;
case 2 :
V_34 = F_33 ( V_11 -> V_12 +
( & V_25 [ V_27 ] ) -> V_36 ) ;
F_29 ( V_11 ) += V_34 ;
if ( F_32 ( V_11 ) < V_34 ) {
F_8 ( V_11 ) ;
return F_28 ( - V_37 ) ;
}
break;
default:
F_8 ( V_11 ) ;
return F_28 ( - V_32 ) ;
}
if ( ! V_34 ) {
( & V_25 [ V_27 ] ) -> V_38 ( V_17 , V_11 ) ;
V_11 = NULL ;
}
} else {
( & V_25 [ V_27 ] ) -> V_38 ( V_17 , V_11 ) ;
V_11 = NULL ;
}
}
return V_11 ;
}
