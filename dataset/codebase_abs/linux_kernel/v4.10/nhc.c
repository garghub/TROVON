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
const struct V_25 * V_26 , T_1 * * V_27 )
{
struct V_1 * V_2 ;
int V_28 = 0 ;
F_9 ( & V_29 ) ;
V_2 = V_30 [ V_26 -> V_31 ] ;
if ( ! ( V_2 && V_2 -> V_32 ) )
V_28 = - V_33 ;
F_10 ( & V_29 ) ;
return V_28 ;
}
int F_11 ( struct V_17 * V_18 , const struct V_25 * V_26 ,
T_1 * * V_27 )
{
int V_28 ;
struct V_1 * V_2 ;
F_9 ( & V_29 ) ;
V_2 = V_30 [ V_26 -> V_31 ] ;
if ( F_12 ( ! V_2 || ! V_2 -> V_32 ) ) {
V_28 = - V_34 ;
goto V_35;
}
if ( V_18 -> V_36 == V_18 -> V_37 )
F_13 ( V_18 , sizeof( struct V_25 ) ) ;
V_28 = V_2 -> V_32 ( V_18 , V_27 ) ;
if ( V_28 < 0 )
goto V_35;
F_14 ( V_18 , V_2 -> V_38 ) ;
V_35:
F_10 ( & V_29 ) ;
return V_28 ;
}
int F_15 ( struct V_17 * V_18 ,
const struct V_39 * V_40 ,
struct V_25 * V_26 )
{
struct V_1 * V_2 ;
int V_28 ;
F_9 ( & V_29 ) ;
V_2 = F_7 ( V_18 ) ;
if ( V_2 ) {
if ( V_2 -> V_41 ) {
V_28 = V_2 -> V_41 ( V_18 , sizeof( struct V_25 ) +
V_2 -> V_38 ) ;
if ( V_28 < 0 ) {
F_10 ( & V_29 ) ;
return V_28 ;
}
} else {
F_10 ( & V_29 ) ;
F_16 ( V_40 , L_1 ,
V_2 -> V_42 ) ;
return - V_43 ;
}
} else {
F_10 ( & V_29 ) ;
F_16 ( V_40 , L_2 ) ;
return - V_33 ;
}
V_26 -> V_31 = V_2 -> V_31 ;
F_17 ( V_18 ) ;
F_18 ( V_44 , L_3 ,
F_19 ( V_18 ) , V_2 -> V_38 ) ;
F_10 ( & V_29 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_28 ;
if ( ! V_2 -> V_12 || ! V_2 -> V_45 )
return - V_34 ;
F_21 ( V_2 -> V_12 > V_22 ,
L_4 ,
V_2 -> V_12 ) ;
V_2 -> V_45 ( V_2 ) ;
F_9 ( & V_29 ) ;
if ( V_30 [ V_2 -> V_31 ] ) {
V_28 = - V_16 ;
goto V_35;
}
V_28 = F_1 ( V_2 ) ;
if ( V_28 < 0 )
goto V_35;
V_30 [ V_2 -> V_31 ] = V_2 ;
V_35:
F_10 ( & V_29 ) ;
return V_28 ;
}
void F_22 ( struct V_1 * V_2 )
{
F_9 ( & V_29 ) ;
F_5 ( V_2 ) ;
V_30 [ V_2 -> V_31 ] = NULL ;
F_10 ( & V_29 ) ;
F_23 () ;
}
