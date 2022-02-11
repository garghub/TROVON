static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * * V_4 = & V_5 . V_3 , * V_6 = NULL ;
while ( * V_4 ) {
struct V_1 * V_7 = F_2 ( * V_4 , struct V_1 ,
V_8 ) ;
int V_9 , V_10 , V_11 ;
V_10 = V_2 -> V_12 - V_7 -> V_12 ;
if ( V_2 -> V_12 < V_7 -> V_12 )
V_11 = V_2 -> V_12 ;
else
V_11 = V_7 -> V_12 ;
V_9 = memcmp ( V_2 -> V_13 , V_7 -> V_13 , V_11 ) ;
if ( ! V_9 )
V_9 = V_10 ;
V_6 = * V_4 ;
if ( V_9 < 0 )
V_4 = & ( ( * V_4 ) -> V_14 ) ;
else if ( V_9 > 0 )
V_4 = & ( ( * V_4 ) -> V_15 ) ;
else
return - V_16 ;
}
F_3 ( & V_2 -> V_8 , V_6 , V_4 ) ;
F_4 ( & V_2 -> V_8 , & V_5 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_8 , & V_5 ) ;
}
static struct V_1 * F_7 ( const struct V_17 * V_18 )
{
struct V_3 * V_8 = V_5 . V_3 ;
const T_1 * V_19 = V_18 -> V_20 ;
while ( V_8 ) {
struct V_1 * V_2 = F_2 ( V_8 , struct V_1 ,
V_8 ) ;
T_1 V_21 [ V_22 ] ;
int V_9 , V_23 ;
if ( V_19 + V_2 -> V_12 > V_18 -> V_20 + V_18 -> V_11 )
return NULL ;
memcpy ( V_21 , V_19 , V_2 -> V_12 ) ;
for ( V_23 = 0 ; V_23 < V_2 -> V_12 ; V_23 ++ )
V_21 [ V_23 ] &= V_2 -> V_24 [ V_23 ] ;
V_9 = memcmp ( V_21 , V_2 -> V_13 , V_2 -> V_12 ) ;
if ( V_9 < 0 )
V_8 = V_8 -> V_14 ;
else if ( V_9 > 0 )
V_8 = V_8 -> V_15 ;
else
return V_2 ;
}
return NULL ;
}
int F_8 ( struct V_17 * V_18 ,
const struct V_25 * V_26 , T_1 * * V_27 ,
T_1 * V_28 )
{
struct V_1 * V_2 ;
F_9 ( & V_29 ) ;
V_2 = V_30 [ V_26 -> V_31 ] ;
if ( V_2 && V_2 -> V_32 )
* V_28 |= V_33 ;
else
F_10 ( V_27 , & V_26 -> V_31 ,
sizeof( V_26 -> V_31 ) ) ;
F_11 ( & V_29 ) ;
return 0 ;
}
int F_12 ( struct V_17 * V_18 , const struct V_25 * V_26 ,
T_1 * * V_27 )
{
int V_34 ;
struct V_1 * V_2 ;
F_9 ( & V_29 ) ;
V_2 = V_30 [ V_26 -> V_31 ] ;
if ( F_13 ( ! V_2 || ! V_2 -> V_32 ) ) {
V_34 = - V_35 ;
goto V_36;
}
if ( V_18 -> V_37 == V_18 -> V_38 )
F_14 ( V_18 , sizeof( struct V_25 ) ) ;
V_34 = V_2 -> V_32 ( V_18 , V_27 ) ;
if ( V_34 < 0 )
goto V_36;
F_15 ( V_18 , V_2 -> V_39 ) ;
V_36:
F_11 ( & V_29 ) ;
return V_34 ;
}
int F_16 ( struct V_17 * V_18 , struct V_40 * V_41 ,
struct V_25 * V_26 )
{
struct V_1 * V_2 ;
int V_34 ;
F_9 ( & V_29 ) ;
V_2 = F_7 ( V_18 ) ;
if ( V_2 ) {
if ( V_2 -> V_42 ) {
V_34 = V_2 -> V_42 ( V_18 , sizeof( struct V_25 ) +
V_2 -> V_39 ) ;
if ( V_34 < 0 ) {
F_11 ( & V_29 ) ;
return V_34 ;
}
} else {
F_11 ( & V_29 ) ;
F_17 ( V_41 , L_1 ,
V_2 -> V_43 ) ;
return - V_44 ;
}
} else {
F_11 ( & V_29 ) ;
F_17 ( V_41 , L_2 ) ;
return - V_45 ;
}
V_26 -> V_31 = V_2 -> V_31 ;
F_18 ( V_18 ) ;
F_19 ( V_46 , L_3 ,
F_20 ( V_18 ) , V_2 -> V_39 ) ;
F_11 ( & V_29 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_34 ;
if ( ! V_2 -> V_12 || ! V_2 -> V_47 )
return - V_35 ;
F_22 ( V_2 -> V_12 > V_22 ,
L_4 ,
V_2 -> V_12 ) ;
V_2 -> V_47 ( V_2 ) ;
F_9 ( & V_29 ) ;
if ( V_30 [ V_2 -> V_31 ] ) {
V_34 = - V_16 ;
goto V_36;
}
V_34 = F_1 ( V_2 ) ;
if ( V_34 < 0 )
goto V_36;
V_30 [ V_2 -> V_31 ] = V_2 ;
V_36:
F_11 ( & V_29 ) ;
return V_34 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_9 ( & V_29 ) ;
F_5 ( V_2 ) ;
V_30 [ V_2 -> V_31 ] = NULL ;
F_11 ( & V_29 ) ;
F_24 () ;
}
