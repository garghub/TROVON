static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
struct V_6 V_7 ;
F_2 ( L_1 , V_4 -> V_8 ) ;
if ( V_4 -> V_9 ) {
F_3 ( V_2 -> V_10 [ V_4 -> V_8 ] . V_9 ) ;
F_2 ( L_2 ) ;
return 0 ;
}
memcpy ( & V_7 , & V_2 -> V_10 [ V_4 -> V_8 ] ,
sizeof( struct V_6 ) ) ;
V_7 . V_9 = 1 ;
F_4 ( & V_2 -> V_11 ) ;
V_5 = F_5 ( V_2 , V_4 -> V_8 , & V_7 ) ;
V_4 -> V_9 = 1 ;
F_6 ( & V_2 -> V_11 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
long long V_12 )
{
int V_5 ;
struct V_6 V_7 ;
F_2 ( L_3 , V_4 -> V_8 ) ;
memcpy ( & V_7 , & V_2 -> V_10 [ V_4 -> V_8 ] ,
sizeof( struct V_6 ) ) ;
F_3 ( V_4 -> V_9 && V_7 . V_9 ) ;
V_7 . V_9 = 0 ;
if ( V_4 -> V_13 == V_14 ) {
V_4 -> V_15 = 0 ;
V_4 -> V_16 = V_12 ;
V_4 -> V_17 = F_8 ( V_12 , V_4 -> V_18 ,
& V_4 -> V_19 ) ;
if ( V_4 -> V_19 )
V_4 -> V_17 += 1 ;
else
V_4 -> V_19 = V_4 -> V_18 ;
}
F_4 ( & V_2 -> V_11 ) ;
V_5 = F_5 ( V_2 , V_4 -> V_8 , & V_7 ) ;
V_4 -> V_9 = 0 ;
F_6 ( & V_2 -> V_11 ) ;
return V_5 ;
}
int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
long long V_12 )
{
int V_20 , V_5 ;
F_2 ( L_4 , V_4 -> V_8 , V_12 ) ;
F_3 ( ! V_4 -> V_21 && ! V_4 -> V_22 ) ;
V_4 -> V_21 = 1 ;
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 )
return V_5 ;
for ( V_20 = 0 ; V_20 < V_4 -> V_23 ; V_20 ++ ) {
V_5 = F_10 ( V_2 , V_4 , V_20 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_12 == 0 ) {
V_5 = F_11 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_7 ( V_2 , V_4 , 0 ) ;
if ( V_5 )
return V_5 ;
V_4 -> V_21 = 0 ;
return 0 ;
}
V_4 -> V_24 = F_12 ( V_2 -> V_25 ) ;
if ( ! V_4 -> V_24 )
return - V_26 ;
V_4 -> V_27 = F_13 ( V_12 + V_4 -> V_18 - 1 ,
V_4 -> V_18 ) ;
V_4 -> V_28 = V_12 ;
V_4 -> V_29 = 0 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_30 * V_31 )
{
F_3 ( ! V_4 -> V_21 && ! V_4 -> V_22 ) ;
F_2 ( L_5 ,
V_4 -> V_8 , V_31 -> V_32 , V_31 -> V_12 ) ;
if ( V_31 -> V_12 == 0 )
return F_15 ( V_2 , V_4 , V_31 -> V_32 , NULL , 0 ,
V_31 -> V_33 ) ;
V_4 -> V_28 = V_31 -> V_12 ;
V_4 -> V_29 = 0 ;
V_4 -> V_22 = 1 ;
V_4 -> V_34 = V_31 -> V_32 ;
V_4 -> V_35 = V_31 -> V_33 ;
V_4 -> V_24 = F_12 ( V_31 -> V_12 ) ;
if ( ! V_4 -> V_24 )
return - V_26 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_32 ,
void * V_36 , int V_37 , int V_17 )
{
int V_5 ;
if ( V_4 -> V_13 == V_38 ) {
int V_39 = F_17 ( V_37 , V_2 -> V_40 ) ;
memset ( V_36 + V_37 , 0xFF , V_39 - V_37 ) ;
V_37 = F_18 ( V_2 , V_36 , V_39 ) ;
if ( V_37 == 0 ) {
F_2 ( L_6 , V_37 ) ;
return 0 ;
}
V_5 = F_19 ( V_2 , V_4 , V_32 , V_36 , 0 , V_37 ,
V_41 ) ;
} else {
memset ( V_36 + V_37 , 0 , V_4 -> V_18 - V_37 ) ;
V_5 = F_20 ( V_2 , V_4 , V_32 , V_36 , V_37 ,
V_41 , V_17 ) ;
}
return V_5 ;
}
int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const void T_1 * V_36 , int V_42 )
{
int V_32 , V_43 , V_5 = 0 , V_37 , V_44 = V_42 ;
F_2 ( L_7 ,
V_42 , V_4 -> V_28 , V_4 -> V_29 ) ;
if ( V_2 -> V_45 )
return - V_46 ;
V_32 = F_8 ( V_4 -> V_29 , V_4 -> V_18 , & V_43 ) ;
if ( V_4 -> V_29 + V_42 > V_4 -> V_28 )
V_44 = V_42 = V_4 -> V_28 - V_4 -> V_29 ;
if ( V_43 != 0 ) {
V_37 = V_4 -> V_18 - V_43 ;
if ( V_37 > V_42 )
V_37 = V_42 ;
V_5 = F_22 ( V_4 -> V_24 + V_43 , V_36 , V_37 ) ;
if ( V_5 )
return - V_47 ;
if ( V_43 + V_37 == V_4 -> V_18 ||
V_4 -> V_29 + V_37 == V_4 -> V_28 ) {
int V_48 = V_43 + V_37 ;
F_3 ( V_48 <= V_4 -> V_18 ) ;
V_5 = F_16 ( V_2 , V_4 , V_32 , V_4 -> V_24 , V_48 ,
V_4 -> V_27 ) ;
if ( V_5 )
return V_5 ;
}
V_4 -> V_29 += V_37 ;
V_42 -= V_37 ;
V_36 += V_37 ;
V_32 += 1 ;
}
while ( V_42 ) {
if ( V_42 > V_4 -> V_18 )
V_37 = V_4 -> V_18 ;
else
V_37 = V_42 ;
V_5 = F_22 ( V_4 -> V_24 , V_36 , V_37 ) ;
if ( V_5 )
return - V_47 ;
if ( V_37 == V_4 -> V_18 ||
V_4 -> V_29 + V_37 == V_4 -> V_28 ) {
V_5 = F_16 ( V_2 , V_4 , V_32 , V_4 -> V_24 ,
V_37 , V_4 -> V_27 ) ;
if ( V_5 )
break;
}
V_4 -> V_29 += V_37 ;
V_42 -= V_37 ;
V_32 += 1 ;
V_36 += V_37 ;
}
F_3 ( V_4 -> V_29 <= V_4 -> V_28 ) ;
if ( V_4 -> V_29 == V_4 -> V_28 ) {
V_5 = F_11 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_7 ( V_2 , V_4 , V_4 -> V_28 ) ;
if ( V_5 )
return V_5 ;
V_4 -> V_21 = 0 ;
V_5 = V_44 ;
F_23 ( V_4 -> V_24 ) ;
}
return V_5 ;
}
int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const void T_1 * V_36 , int V_42 )
{
int V_5 ;
F_2 ( L_7 ,
V_42 , V_4 -> V_28 , V_4 -> V_29 ) ;
if ( V_2 -> V_45 )
return - V_46 ;
if ( V_4 -> V_29 + V_42 > V_4 -> V_28 )
V_42 = V_4 -> V_28 - V_4 -> V_29 ;
V_5 = F_22 ( V_4 -> V_24 + V_4 -> V_29 , V_36 , V_42 ) ;
if ( V_5 )
return - V_47 ;
V_4 -> V_29 += V_42 ;
if ( V_4 -> V_29 == V_4 -> V_28 ) {
int V_37 = F_17 ( ( int ) V_4 -> V_28 , V_2 -> V_40 ) ;
memset ( V_4 -> V_24 + V_4 -> V_28 , 0xFF ,
V_37 - V_4 -> V_28 ) ;
V_37 = F_18 ( V_2 , V_4 -> V_24 , V_37 ) ;
V_5 = F_15 ( V_2 , V_4 , V_4 -> V_34 ,
V_4 -> V_24 , V_37 , V_41 ) ;
if ( V_5 )
return V_5 ;
}
F_3 ( V_4 -> V_29 <= V_4 -> V_28 ) ;
if ( V_4 -> V_29 == V_4 -> V_28 ) {
V_4 -> V_22 = 0 ;
V_5 = V_42 ;
F_23 ( V_4 -> V_24 ) ;
}
return V_5 ;
}
