static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_14 * V_15 ;
int V_16 ;
V_15 = F_4 ( V_12 -> V_17 , V_6 ) ;
V_16 = F_5 ( V_6 , V_8 , V_10 ) ;
if ( V_16 )
return V_16 ;
F_6 ( V_6 , V_15 ,
V_10 ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_1 * V_18 = F_1 ( V_12 -> V_4 ) ;
struct V_19 * V_20 = F_8 ( V_6 ) ;
struct V_9 V_10 ;
int V_16 ;
if ( V_18 -> V_21 -> V_22 ) {
V_16 = V_18 -> V_21 -> V_22 ( V_6 , V_8 ,
& V_10 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_9 ( V_20 , & V_10 ) ;
if ( V_16 )
return V_16 ;
}
return F_10 ( V_6 , F_11 ( V_8 ) ) ;
}
static int F_12 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_1 * V_18 = F_1 ( V_12 -> V_4 ) ;
struct V_19 * V_20 = V_18 -> V_20 [ V_6 -> V_23 ] ;
int V_16 ;
V_16 = F_13 ( V_6 ,
V_18 -> V_21 -> V_24 ) ;
if ( V_16 )
return V_16 ;
return F_14 ( V_6 , V_20 ) ;
}
static struct V_25 * F_15 ( struct V_1 * V_18 ,
struct V_5 * V_6 )
{
if ( ! V_18 -> V_20 [ V_6 -> V_23 ] )
return NULL ;
return V_18 -> V_20 [ V_6 -> V_23 ] -> V_25 -> V_26 ;
}
static void F_16 ( struct V_27 * V_18 )
{
F_17 ( V_18 ) ;
}
static struct V_19 * F_18 (
struct V_11 * V_12 ,
struct V_5 * V_6 )
{
struct V_1 * V_18 = F_1 ( V_12 -> V_4 ) ;
if ( ( V_18 -> V_28 & V_29 ) && V_18 -> V_20 [ 0 ] )
return V_18 -> V_20 [ 0 ] ;
if ( V_18 -> V_21 -> V_30 )
return V_18 -> V_21 -> V_30 ( V_12 , V_6 ) ;
return F_19 ( V_18 -> V_21 -> V_31 ,
F_4 ( V_12 -> V_17 , V_6 ) ) ;
}
static int F_20 ( struct V_11 * V_12 )
{
struct V_1 * V_18 = F_1 ( V_12 -> V_4 ) ;
const struct V_32 * V_21 = V_18 -> V_21 ;
struct V_5 * V_6 ;
unsigned int V_33 ;
int V_16 ;
for ( V_33 = V_34 ; V_33 <= V_35 ; V_33 ++ ) {
V_6 = V_12 -> V_18 -> V_36 [ V_33 ] . V_6 ;
if ( ! V_6 )
continue;
if ( ! V_18 -> V_20 [ V_33 ] && ( V_18 -> V_28 & V_37 ) ) {
V_18 -> V_20 [ V_33 ] = F_18 ( V_12 ,
V_6 ) ;
}
if ( ! V_18 -> V_20 [ V_33 ] ) {
F_21 ( V_12 -> V_4 -> V_26 ,
L_1 , V_33 ) ;
V_16 = - V_38 ;
goto V_39;
}
V_16 = F_22 ( V_6 ,
V_40 ,
F_15 ( V_18 , V_6 ) ,
V_21 -> V_41 ,
V_21 -> V_24 -> V_42 ) ;
if ( V_16 )
goto V_39;
}
return 0 ;
V_39:
F_16 ( V_12 -> V_18 ) ;
return V_16 ;
}
static void F_23 ( struct V_1 * V_18 ,
struct V_25 * V_26 )
{
unsigned int V_33 ;
if ( ( V_18 -> V_28 & V_43 ) || ! V_26 -> V_44 )
return;
if ( V_18 -> V_28 & V_29 ) {
V_18 -> V_20 [ 0 ] = F_24 ( V_26 , L_2 ) ;
V_18 -> V_20 [ 1 ] = V_18 -> V_20 [ 0 ] ;
} else {
for ( V_33 = V_34 ; V_33 <= V_35 ; V_33 ++ ) {
V_18 -> V_20 [ V_33 ] = F_24 ( V_26 ,
V_45 [ V_33 ] ) ;
}
}
}
int F_25 ( struct V_25 * V_26 ,
const struct V_32 * V_21 , unsigned int V_28 )
{
struct V_1 * V_18 ;
V_18 = F_26 ( sizeof( * V_18 ) , V_46 ) ;
if ( ! V_18 )
return - V_47 ;
V_18 -> V_21 = V_21 ;
V_18 -> V_28 = V_28 ;
F_23 ( V_18 , V_26 ) ;
if ( V_28 & V_48 )
return F_27 ( V_26 , & V_18 -> V_4 ,
& V_49 ) ;
else
return F_27 ( V_26 , & V_18 -> V_4 ,
& V_50 ) ;
}
void F_28 ( struct V_25 * V_26 )
{
struct V_2 * V_4 ;
struct V_1 * V_18 ;
unsigned int V_33 ;
V_4 = F_29 ( V_26 ) ;
if ( ! V_4 )
return;
V_18 = F_1 ( V_4 ) ;
for ( V_33 = V_34 ; V_33 <= V_35 ; V_33 ++ ) {
if ( V_18 -> V_20 [ V_33 ] ) {
F_30 ( V_18 -> V_20 [ V_33 ] ) ;
if ( V_18 -> V_28 & V_29 )
break;
}
}
F_31 ( V_4 ) ;
F_32 ( V_18 ) ;
}
