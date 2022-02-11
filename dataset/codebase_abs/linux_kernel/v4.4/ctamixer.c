static int F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 = 0 ;
return V_1 -> V_3 = F_2 ( V_1 , struct V_4 , V_1 ) -> V_3 [ 0 ] ;
}
static int F_3 ( struct V_1 * V_1 )
{
V_1 -> V_2 ++ ;
return F_2 ( V_1 , struct V_4 , V_1 ) -> V_3 [ V_1 -> V_2 ] ;
}
static int F_4 ( const struct V_1 * V_1 )
{
return F_2 ( V_1 , struct V_4 , V_1 ) -> V_3 [ V_1 -> V_2 ] ;
}
static int F_5 ( const struct V_1 * V_1 )
{
return ( F_4 ( V_1 ) << 4 ) + 0x4 ;
}
static int F_6 ( struct V_4 * V_4 , struct V_1 * V_1 )
{
struct V_5 * V_5 ;
V_5 = V_4 -> V_1 . V_5 ;
V_5 -> V_6 ( V_4 -> V_1 . V_7 , V_8 ) ;
V_4 -> V_9 = V_1 ;
if ( ! V_1 )
V_5 -> V_10 ( V_4 -> V_1 . V_7 , V_11 ) ;
else
V_5 -> V_10 ( V_4 -> V_1 . V_7 ,
V_1 -> V_12 -> V_13 ( V_1 ) ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_4 , unsigned int V_14 )
{
struct V_5 * V_5 ;
V_5 = V_4 -> V_1 . V_5 ;
V_5 -> F_7 ( V_4 -> V_1 . V_7 , V_14 ) ;
return 0 ;
}
static int F_8 ( struct V_4 * V_4 , unsigned int V_15 )
{
struct V_5 * V_5 ;
V_5 = V_4 -> V_1 . V_5 ;
V_5 -> V_16 ( V_4 -> V_1 . V_7 , V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_4 , struct V_17 * V_17 )
{
struct V_5 * V_5 ;
V_5 = V_4 -> V_1 . V_5 ;
V_4 -> V_17 = V_17 ;
if ( ! V_17 ) {
V_5 -> V_18 ( V_4 -> V_1 . V_7 , 0 ) ;
} else {
V_5 -> V_18 ( V_4 -> V_1 . V_7 , 1 ) ;
V_5 -> V_19 ( V_4 -> V_1 . V_7 ,
V_17 -> V_1 . V_12 -> V_20 ( & V_17 -> V_1 ) ) ;
}
return 0 ;
}
static int F_10 ( struct V_4 * V_4 )
{
struct V_5 * V_5 ;
unsigned int V_20 ;
int V_21 ;
struct V_1 * V_9 ;
struct V_17 * V_17 ;
V_5 = V_4 -> V_1 . V_5 ;
V_9 = V_4 -> V_9 ;
V_17 = V_4 -> V_17 ;
V_4 -> V_1 . V_12 -> V_22 ( & V_4 -> V_1 ) ;
if ( V_9 )
V_9 -> V_12 -> V_22 ( V_9 ) ;
if ( V_17 )
V_17 -> V_1 . V_12 -> V_22 ( & V_17 -> V_1 ) ;
for ( V_21 = 0 ; V_21 < V_4 -> V_1 . V_23 ; V_21 ++ ) {
V_5 -> V_24 ( V_4 -> V_1 . V_7 ) ;
if ( V_9 ) {
V_5 -> V_10 ( V_4 -> V_1 . V_7 ,
V_9 -> V_12 -> V_13 ( V_9 ) ) ;
V_9 -> V_12 -> V_25 ( V_9 ) ;
}
if ( V_17 ) {
V_5 -> V_19 ( V_4 -> V_1 . V_7 ,
V_17 -> V_1 . V_12 -> V_20 ( & V_17 -> V_1 ) ) ;
V_17 -> V_1 . V_12 -> V_25 ( & V_17 -> V_1 ) ;
}
V_20 = V_4 -> V_1 . V_12 -> V_13 ( & V_4 -> V_1 ) ;
V_5 -> F_10 ( V_5 , V_20 , V_4 -> V_1 . V_7 ) ;
V_4 -> V_1 . V_12 -> V_25 ( & V_4 -> V_1 ) ;
}
V_4 -> V_1 . V_12 -> V_22 ( & V_4 -> V_1 ) ;
if ( V_9 )
V_9 -> V_12 -> V_22 ( V_9 ) ;
if ( V_17 )
V_17 -> V_1 . V_12 -> V_22 ( & V_17 -> V_1 ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_4 )
{
struct V_5 * V_5 ;
unsigned int V_20 ;
V_5 = V_4 -> V_1 . V_5 ;
V_20 = V_4 -> V_1 . V_12 -> V_13 ( & V_4 -> V_1 ) ;
V_5 -> F_10 ( V_5 , V_20 , V_4 -> V_1 . V_7 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_4 )
{
struct V_5 * V_5 ;
V_5 = V_4 -> V_1 . V_5 ;
return V_5 -> F_12 ( V_4 -> V_1 . V_7 ) ;
}
static int F_13 ( struct V_4 * V_4 , struct V_1 * V_9 ,
unsigned int V_26 , struct V_17 * V_17 )
{
F_6 ( V_4 , V_9 ) ;
F_7 ( V_4 , V_26 ) ;
F_9 ( V_4 , V_17 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_4 ,
const struct V_27 * V_28 ,
struct V_29 * V_30 )
{
int V_31 ;
V_31 = F_15 ( & V_4 -> V_1 , V_4 -> V_3 [ 0 ] ,
V_32 , V_28 -> V_23 , V_30 -> V_30 . V_5 ) ;
if ( V_31 )
return V_31 ;
V_4 -> V_1 . V_12 = & V_33 ;
V_4 -> V_12 = & V_34 ;
V_4 -> V_9 = NULL ;
V_4 -> V_17 = NULL ;
F_13 ( V_4 , NULL , 0 , NULL ) ;
return 0 ;
}
static int F_16 ( struct V_4 * V_4 )
{
F_13 ( V_4 , NULL , 0 , NULL ) ;
F_17 ( & V_4 -> V_1 ) ;
V_4 -> V_12 = NULL ;
V_4 -> V_9 = NULL ;
V_4 -> V_17 = NULL ;
return 0 ;
}
static int F_18 ( struct V_29 * V_30 ,
const struct V_27 * V_28 ,
struct V_4 * * V_35 )
{
int V_31 , V_21 ;
unsigned int V_3 ;
struct V_4 * V_4 ;
unsigned long V_36 ;
* V_35 = NULL ;
V_4 = F_19 ( sizeof( * V_4 ) , V_37 ) ;
if ( ! V_4 )
return - V_38 ;
V_31 = 0 ;
F_20 ( & V_30 -> V_39 , V_36 ) ;
for ( V_21 = 0 ; V_21 < V_28 -> V_23 ; V_21 ++ ) {
V_31 = F_21 ( & V_30 -> V_30 , 1 , & V_3 ) ;
if ( V_31 )
break;
V_4 -> V_3 [ V_21 ] = V_3 ;
}
F_22 ( & V_30 -> V_39 , V_36 ) ;
if ( V_31 ) {
F_23 ( V_30 -> V_40 -> V_41 ,
L_1 ) ;
goto error;
}
V_31 = F_14 ( V_4 , V_28 , V_30 ) ;
if ( V_31 )
goto error;
* V_35 = V_4 ;
return 0 ;
error:
F_20 ( & V_30 -> V_39 , V_36 ) ;
for ( V_21 -- ; V_21 >= 0 ; V_21 -- )
F_24 ( & V_30 -> V_30 , 1 , V_4 -> V_3 [ V_21 ] ) ;
F_22 ( & V_30 -> V_39 , V_36 ) ;
F_25 ( V_4 ) ;
return V_31 ;
}
static int F_26 ( struct V_29 * V_30 , struct V_4 * V_4 )
{
unsigned long V_36 ;
int V_21 ;
F_20 ( & V_30 -> V_39 , V_36 ) ;
for ( V_21 = 0 ; V_21 < V_4 -> V_1 . V_23 ; V_21 ++ )
F_24 ( & V_30 -> V_30 , 1 , V_4 -> V_3 [ V_21 ] ) ;
F_22 ( & V_30 -> V_39 , V_36 ) ;
F_16 ( V_4 ) ;
F_25 ( V_4 ) ;
return 0 ;
}
int F_27 ( struct V_5 * V_5 , struct V_29 * * V_42 )
{
int V_31 ;
struct V_29 * V_29 ;
* V_42 = NULL ;
V_29 = F_19 ( sizeof( * V_29 ) , V_37 ) ;
if ( ! V_29 )
return - V_38 ;
V_31 = F_28 ( & V_29 -> V_30 , V_32 , V_43 , V_5 ) ;
if ( V_31 )
goto error;
F_29 ( & V_29 -> V_39 ) ;
V_29 -> V_44 = F_18 ;
V_29 -> V_45 = F_26 ;
V_29 -> V_40 = V_5 -> V_40 ;
* V_42 = V_29 ;
return 0 ;
error:
F_25 ( V_29 ) ;
return V_31 ;
}
int F_30 ( struct V_29 * V_29 )
{
F_31 ( & V_29 -> V_30 ) ;
F_25 ( V_29 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 )
{
V_1 -> V_2 = 0 ;
return V_1 -> V_3 = F_2 ( V_1 , struct V_17 , V_1 ) -> V_3 [ 0 ] ;
}
static int F_33 ( struct V_1 * V_1 )
{
V_1 -> V_2 ++ ;
return F_2 ( V_1 , struct V_17 , V_1 ) -> V_3 [ V_1 -> V_2 ] ;
}
static int F_34 ( const struct V_1 * V_1 )
{
return F_2 ( V_1 , struct V_17 , V_1 ) -> V_3 [ V_1 -> V_2 ] ;
}
static int F_35 ( const struct V_1 * V_1 )
{
return ( F_34 ( V_1 ) << 4 ) + 0xc ;
}
static int F_36 ( struct V_17 * V_17 ,
const struct V_46 * V_28 ,
struct V_47 * V_30 )
{
int V_31 ;
V_31 = F_15 ( & V_17 -> V_1 , V_17 -> V_3 [ 0 ] , V_48 , V_28 -> V_23 , V_30 -> V_30 . V_5 ) ;
if ( V_31 )
return V_31 ;
V_17 -> V_1 . V_12 = & V_49 ;
return 0 ;
}
static int F_37 ( struct V_17 * V_17 )
{
F_17 ( & V_17 -> V_1 ) ;
return 0 ;
}
static int F_38 ( struct V_47 * V_30 ,
const struct V_46 * V_28 ,
struct V_17 * * V_50 )
{
int V_31 , V_21 ;
unsigned int V_3 ;
struct V_17 * V_17 ;
unsigned long V_36 ;
* V_50 = NULL ;
V_17 = F_19 ( sizeof( * V_17 ) , V_37 ) ;
if ( ! V_17 )
return - V_38 ;
V_31 = 0 ;
F_20 ( & V_30 -> V_39 , V_36 ) ;
for ( V_21 = 0 ; V_21 < V_28 -> V_23 ; V_21 ++ ) {
V_31 = F_21 ( & V_30 -> V_30 , 1 , & V_3 ) ;
if ( V_31 )
break;
V_17 -> V_3 [ V_21 ] = V_3 ;
}
F_22 ( & V_30 -> V_39 , V_36 ) ;
if ( V_31 ) {
F_23 ( V_30 -> V_40 -> V_41 ,
L_2 ) ;
goto error;
}
V_31 = F_36 ( V_17 , V_28 , V_30 ) ;
if ( V_31 )
goto error;
* V_50 = V_17 ;
return 0 ;
error:
F_20 ( & V_30 -> V_39 , V_36 ) ;
for ( V_21 -- ; V_21 >= 0 ; V_21 -- )
F_24 ( & V_30 -> V_30 , 1 , V_17 -> V_3 [ V_21 ] ) ;
F_22 ( & V_30 -> V_39 , V_36 ) ;
F_25 ( V_17 ) ;
return V_31 ;
}
static int F_39 ( struct V_47 * V_30 , struct V_17 * V_17 )
{
unsigned long V_36 ;
int V_21 ;
F_20 ( & V_30 -> V_39 , V_36 ) ;
for ( V_21 = 0 ; V_21 < V_17 -> V_1 . V_23 ; V_21 ++ )
F_24 ( & V_30 -> V_30 , 1 , V_17 -> V_3 [ V_21 ] ) ;
F_22 ( & V_30 -> V_39 , V_36 ) ;
F_37 ( V_17 ) ;
F_25 ( V_17 ) ;
return 0 ;
}
int F_40 ( struct V_5 * V_5 , struct V_47 * * V_51 )
{
int V_31 ;
struct V_47 * V_47 ;
* V_51 = NULL ;
V_47 = F_19 ( sizeof( * V_47 ) , V_37 ) ;
if ( ! V_47 )
return - V_38 ;
V_31 = F_28 ( & V_47 -> V_30 , V_48 , V_52 , V_5 ) ;
if ( V_31 )
goto error;
F_29 ( & V_47 -> V_39 ) ;
V_47 -> V_53 = F_38 ;
V_47 -> V_54 = F_39 ;
V_47 -> V_40 = V_5 -> V_40 ;
* V_51 = V_47 ;
return 0 ;
error:
F_25 ( V_47 ) ;
return V_31 ;
}
int F_41 ( struct V_47 * V_47 )
{
F_31 ( & V_47 -> V_30 ) ;
F_25 ( V_47 ) ;
return 0 ;
}
