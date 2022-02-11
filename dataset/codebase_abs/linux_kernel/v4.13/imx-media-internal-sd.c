static inline void F_1 ( char * V_1 , int V_2 ,
const struct V_3 * V_4 ,
int V_5 )
{
int V_6 = V_5 * V_7 + V_4 -> V_8 ;
snprintf ( V_1 , V_2 , L_1 , V_4 -> V_9 , V_6 ) ;
}
static int F_2 ( struct V_10 * V_11 ,
const struct V_12 * V_13 ,
struct V_14 * V_15 ,
int V_5 )
{
int V_16 , V_17 , V_18 ;
V_17 = V_13 -> V_19 + V_13 -> V_20 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
const struct V_21 * V_22 = & V_13 -> V_23 [ V_16 ] ;
struct V_24 * V_23 = & V_15 -> V_23 [ V_16 ] ;
int V_25 ;
V_23 -> V_23 . V_26 = ( V_16 < V_13 -> V_19 ) ?
V_27 : V_28 ;
V_23 -> V_29 = V_22 -> V_29 ;
for ( V_25 = 0 ; ; V_25 ++ ) {
const struct V_30 * V_31 ;
char V_32 [ 32 ] ;
V_31 = & V_22 -> V_31 [ V_25 ] ;
if ( ! V_31 -> V_33 )
break;
F_1 ( V_32 ,
sizeof( V_32 ) ,
V_31 -> V_33 , V_5 ) ;
V_18 = F_3 ( V_11 , V_23 ,
NULL , V_32 ,
V_16 , V_31 -> V_34 ) ;
if ( V_18 )
return V_18 ;
}
}
return 0 ;
}
static struct V_14 *
F_4 ( struct V_10 * V_11 ,
const struct V_12 * V_13 ,
int V_5 )
{
struct V_35 V_36 ;
struct V_37 V_38 = { 0 } ;
struct V_14 * V_15 ;
struct V_39 * V_40 ;
V_36 . V_41 = V_13 -> V_4 -> V_41 ;
V_36 . V_5 = V_5 ;
F_5 ( V_36 . V_42 , sizeof( V_36 . V_42 ) ,
V_36 . V_41 , V_5 ) ;
V_38 . V_9 = V_13 -> V_4 -> V_9 ;
V_38 . V_4 = V_5 * V_7 + V_13 -> V_4 -> V_8 ;
V_38 . V_43 = V_11 -> V_44 . V_45 ;
V_38 . V_46 = & V_36 ;
V_38 . V_47 = sizeof( V_36 ) ;
V_38 . V_48 = F_6 ( 32 ) ;
V_40 = F_7 ( & V_38 ) ;
if ( F_8 ( V_40 ) )
return F_9 ( V_40 ) ;
V_15 = F_10 ( V_11 , NULL , V_40 ) ;
if ( F_8 ( V_15 ) )
return V_15 ;
V_15 -> V_19 = V_13 -> V_19 ;
V_15 -> V_20 = V_13 -> V_20 ;
return V_15 ;
}
static int F_11 ( struct V_10 * V_11 ,
struct V_14 * V_49 ,
struct V_14 * V_50 ,
int V_5 )
{
enum V_51 V_16 ;
int V_18 ;
for ( V_16 = 0 ; V_16 < V_7 ; V_16 ++ ) {
const struct V_12 * V_13 = & V_12 [ V_16 ] ;
struct V_14 * V_15 ;
switch ( V_13 -> V_4 -> V_41 ) {
case V_52 :
V_15 = V_49 ;
break;
case V_53 :
V_15 = V_50 ;
break;
default:
V_15 = F_4 ( V_11 , V_13 , V_5 ) ;
break;
}
if ( F_8 ( V_15 ) )
return F_12 ( V_15 ) ;
if ( V_15 ) {
V_18 = F_2 ( V_11 , V_13 , V_15 , V_5 ) ;
if ( V_18 )
return V_18 ;
}
}
return 0 ;
}
int F_13 ( struct V_10 * V_11 ,
struct V_14 * V_54 [ 4 ] )
{
int V_18 ;
V_18 = F_11 ( V_11 , V_54 [ 0 ] , V_54 [ 1 ] , 0 ) ;
if ( V_18 )
goto remove;
V_18 = F_11 ( V_11 , V_54 [ 2 ] , V_54 [ 3 ] , 1 ) ;
if ( V_18 )
goto remove;
return 0 ;
remove:
F_14 ( V_11 ) ;
return V_18 ;
}
void F_14 ( struct V_10 * V_11 )
{
struct V_14 * V_15 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_11 -> V_55 . V_56 ; V_16 ++ ) {
V_15 = & V_11 -> V_57 [ V_16 ] ;
if ( ! V_15 -> V_40 )
continue;
F_15 ( V_15 -> V_40 ) ;
}
}
