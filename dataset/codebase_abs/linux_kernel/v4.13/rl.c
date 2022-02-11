int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_2 * V_5 )
{
T_2 V_6 [ F_2 ( V_7 ) ] = { 0 } ;
T_2 V_8 [ F_2 ( V_7 ) ] = { 0 } ;
void * V_9 ;
int V_10 ;
V_9 = F_3 ( V_7 , V_6 ,
V_11 ) ;
F_4 ( V_7 , V_6 , V_12 ,
V_13 ) ;
F_4 ( V_7 , V_6 , V_14 ,
V_3 ) ;
memcpy ( V_9 , V_4 , F_5 ( V_11 ) ) ;
V_10 = F_6 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
if ( V_10 )
return V_10 ;
* V_5 = F_7 ( V_15 , V_8 ,
V_16 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_2 V_5 ,
T_2 V_17 )
{
T_2 V_6 [ F_2 ( V_18 ) ] = { 0 } ;
T_2 V_8 [ F_2 ( V_18 ) ] = { 0 } ;
void * V_9 ;
V_9 = F_3 ( V_18 , V_6 ,
V_11 ) ;
F_4 ( V_18 , V_6 , V_12 ,
V_19 ) ;
F_4 ( V_18 , V_6 , V_16 ,
V_5 ) ;
F_4 ( V_18 , V_6 , V_17 ,
V_17 ) ;
F_4 ( V_18 , V_6 , V_14 ,
V_3 ) ;
memcpy ( V_9 , V_4 , F_5 ( V_11 ) ) ;
return F_6 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_5 )
{
T_2 V_6 [ F_2 ( V_20 ) ] = { 0 } ;
T_2 V_8 [ F_2 ( V_20 ) ] = { 0 } ;
F_4 ( V_20 , V_6 , V_12 ,
V_21 ) ;
F_4 ( V_20 , V_6 , V_16 ,
V_5 ) ;
F_4 ( V_20 , V_6 , V_14 ,
V_3 ) ;
return F_6 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
static struct V_22 * F_10 ( struct V_23 * V_24 ,
T_2 V_25 )
{
struct V_22 * V_26 = NULL ;
bool V_27 = false ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_24 -> V_29 ; V_28 ++ ) {
if ( V_24 -> V_30 [ V_28 ] . V_25 == V_25 )
return & V_24 -> V_30 [ V_28 ] ;
if ( ! V_27 && ! V_24 -> V_30 [ V_28 ] . V_25 ) {
V_27 = true ;
V_26 = & V_24 -> V_30 [ V_28 ] ;
}
}
return V_26 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_2 V_25 , T_3 V_31 )
{
T_2 V_6 [ F_2 ( V_32 ) ] = { 0 } ;
T_2 V_8 [ F_2 ( V_33 ) ] = { 0 } ;
F_4 ( V_32 , V_6 , V_12 ,
V_34 ) ;
F_4 ( V_32 , V_6 , V_35 , V_31 ) ;
F_4 ( V_32 , V_6 , V_36 , V_25 ) ;
return F_6 ( V_2 , V_6 , sizeof( V_6 ) , V_8 , sizeof( V_8 ) ) ;
}
bool F_12 ( struct V_1 * V_2 , T_2 V_25 )
{
struct V_23 * V_24 = & V_2 -> V_37 . V_38 ;
return ( V_25 <= V_24 -> V_39 && V_25 >= V_24 -> V_40 ) ;
}
int F_13 ( struct V_1 * V_2 , T_2 V_25 , T_3 * V_31 )
{
struct V_23 * V_24 = & V_2 -> V_37 . V_38 ;
struct V_22 * V_41 ;
int V_10 = 0 ;
F_14 ( & V_24 -> V_42 ) ;
if ( ! V_25 || ! F_12 ( V_2 , V_25 ) ) {
F_15 ( V_2 , L_1 ,
V_25 , V_24 -> V_40 , V_24 -> V_39 ) ;
V_10 = - V_43 ;
goto V_8;
}
V_41 = F_10 ( V_24 , V_25 ) ;
if ( ! V_41 ) {
F_15 ( V_2 , L_2 ,
V_24 -> V_29 ) ;
V_10 = - V_44 ;
goto V_8;
}
if ( V_41 -> V_45 ) {
V_41 -> V_45 ++ ;
} else {
V_10 = F_11 ( V_2 , V_25 , V_41 -> V_31 ) ;
if ( V_10 ) {
F_15 ( V_2 , L_3 ,
V_25 , V_10 ) ;
goto V_8;
}
V_41 -> V_25 = V_25 ;
V_41 -> V_45 = 1 ;
}
* V_31 = V_41 -> V_31 ;
V_8:
F_16 ( & V_24 -> V_42 ) ;
return V_10 ;
}
void F_17 ( struct V_1 * V_2 , T_2 V_25 )
{
struct V_23 * V_24 = & V_2 -> V_37 . V_38 ;
struct V_22 * V_41 = NULL ;
if ( V_25 == 0 )
return;
F_14 ( & V_24 -> V_42 ) ;
V_41 = F_10 ( V_24 , V_25 ) ;
if ( ! V_41 || ! V_41 -> V_45 ) {
F_18 ( V_2 , L_4 , V_25 ) ;
goto V_8;
}
V_41 -> V_45 -- ;
if ( ! V_41 -> V_45 ) {
F_11 ( V_2 , 0 , V_41 -> V_31 ) ;
V_41 -> V_25 = 0 ;
}
V_8:
F_16 ( & V_24 -> V_42 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_2 -> V_37 . V_38 ;
int V_28 ;
F_20 ( & V_24 -> V_42 ) ;
if ( ! F_21 ( V_2 , V_46 ) || ! F_22 ( V_2 , V_47 ) ) {
V_24 -> V_29 = 0 ;
return 0 ;
}
V_24 -> V_29 = F_22 ( V_2 , V_48 ) - 1 ;
V_24 -> V_39 = F_22 ( V_2 , V_49 ) ;
V_24 -> V_40 = F_22 ( V_2 , V_50 ) ;
V_24 -> V_30 = F_23 ( V_24 -> V_29 , sizeof( struct V_22 ) ,
V_51 ) ;
if ( ! V_24 -> V_30 )
return - V_52 ;
for ( V_28 = 0 ; V_28 < V_24 -> V_29 ; V_28 ++ )
V_24 -> V_30 [ V_28 ] . V_31 = V_28 + 1 ;
F_24 ( V_2 , L_5 ,
V_24 -> V_29 ,
V_24 -> V_40 >> 10 ,
V_24 -> V_39 >> 10 ) ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_2 -> V_37 . V_38 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_24 -> V_29 ; V_28 ++ )
if ( V_24 -> V_30 [ V_28 ] . V_25 )
F_11 ( V_2 , 0 ,
V_24 -> V_30 [ V_28 ] . V_31 ) ;
F_26 ( V_2 -> V_37 . V_38 . V_30 ) ;
}
