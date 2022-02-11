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
V_7 = V_2 -> V_10 [ V_4 -> V_8 ] ;
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
V_7 = V_2 -> V_10 [ V_4 -> V_8 ] ;
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
V_4 -> V_23 = F_10 ( V_2 -> V_24 ) ;
if ( ! V_4 -> V_23 )
return - V_25 ;
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 )
return V_5 ;
for ( V_20 = 0 ; V_20 < V_4 -> V_26 ; V_20 ++ ) {
V_5 = F_11 ( V_2 , V_4 , V_20 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_12 == 0 ) {
V_5 = F_12 ( V_2 , V_27 , V_27 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_7 ( V_2 , V_4 , 0 ) ;
if ( V_5 )
return V_5 ;
F_13 ( V_4 -> V_23 ) ;
V_4 -> V_21 = 0 ;
return 0 ;
}
V_4 -> V_28 = F_14 ( V_12 + V_4 -> V_18 - 1 ,
V_4 -> V_18 ) ;
V_4 -> V_29 = V_12 ;
V_4 -> V_30 = 0 ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_31 * V_32 )
{
F_3 ( ! V_4 -> V_21 && ! V_4 -> V_22 ) ;
F_2 ( L_5 ,
V_4 -> V_8 , V_32 -> V_33 , V_32 -> V_12 ) ;
if ( V_32 -> V_12 == 0 )
return F_16 ( V_2 , V_4 , V_32 -> V_33 , NULL , 0 ) ;
V_4 -> V_29 = V_32 -> V_12 ;
V_4 -> V_30 = 0 ;
V_4 -> V_22 = 1 ;
V_4 -> V_34 = V_32 -> V_33 ;
V_4 -> V_23 = F_10 ( F_17 ( ( int ) V_32 -> V_12 , V_2 -> V_35 ) ) ;
if ( ! V_4 -> V_23 )
return - V_25 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_33 ,
void * V_36 , int V_37 , int V_17 )
{
int V_5 ;
if ( V_4 -> V_13 == V_38 ) {
int V_39 = F_17 ( V_37 , V_2 -> V_35 ) ;
memset ( V_36 + V_37 , 0xFF , V_39 - V_37 ) ;
V_37 = F_19 ( V_2 , V_36 , V_39 ) ;
if ( V_37 == 0 ) {
F_2 ( L_6 , V_37 ) ;
return 0 ;
}
V_5 = F_20 ( V_2 , V_4 , V_33 , V_36 , 0 , V_37 ) ;
} else {
memset ( V_36 + V_37 , 0 , V_4 -> V_18 - V_37 ) ;
V_5 = F_21 ( V_2 , V_4 , V_33 , V_36 , V_37 , V_17 ) ;
}
return V_5 ;
}
int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const void T_1 * V_36 , int V_40 )
{
int V_33 , V_41 , V_5 = 0 , V_37 , V_42 = V_40 ;
F_2 ( L_7 ,
V_40 , V_4 -> V_29 , V_4 -> V_30 ) ;
if ( V_2 -> V_43 )
return - V_44 ;
V_33 = F_8 ( V_4 -> V_30 , V_4 -> V_18 , & V_41 ) ;
if ( V_4 -> V_30 + V_40 > V_4 -> V_29 )
V_42 = V_40 = V_4 -> V_29 - V_4 -> V_30 ;
if ( V_41 != 0 ) {
V_37 = V_4 -> V_18 - V_41 ;
if ( V_37 > V_40 )
V_37 = V_40 ;
V_5 = F_23 ( V_4 -> V_23 + V_41 , V_36 , V_37 ) ;
if ( V_5 )
return - V_45 ;
if ( V_41 + V_37 == V_4 -> V_18 ||
V_4 -> V_30 + V_37 == V_4 -> V_29 ) {
int V_46 = V_41 + V_37 ;
F_3 ( V_46 <= V_4 -> V_18 ) ;
V_5 = F_18 ( V_2 , V_4 , V_33 , V_4 -> V_23 , V_46 ,
V_4 -> V_28 ) ;
if ( V_5 )
return V_5 ;
}
V_4 -> V_30 += V_37 ;
V_40 -= V_37 ;
V_36 += V_37 ;
V_33 += 1 ;
}
while ( V_40 ) {
if ( V_40 > V_4 -> V_18 )
V_37 = V_4 -> V_18 ;
else
V_37 = V_40 ;
V_5 = F_23 ( V_4 -> V_23 , V_36 , V_37 ) ;
if ( V_5 )
return - V_45 ;
if ( V_37 == V_4 -> V_18 ||
V_4 -> V_30 + V_37 == V_4 -> V_29 ) {
V_5 = F_18 ( V_2 , V_4 , V_33 , V_4 -> V_23 ,
V_37 , V_4 -> V_28 ) ;
if ( V_5 )
break;
}
V_4 -> V_30 += V_37 ;
V_40 -= V_37 ;
V_33 += 1 ;
V_36 += V_37 ;
}
F_3 ( V_4 -> V_30 <= V_4 -> V_29 ) ;
if ( V_4 -> V_30 == V_4 -> V_29 ) {
V_5 = F_12 ( V_2 , V_27 , V_27 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_7 ( V_2 , V_4 , V_4 -> V_29 ) ;
if ( V_5 )
return V_5 ;
V_4 -> V_21 = 0 ;
V_5 = V_42 ;
F_13 ( V_4 -> V_23 ) ;
}
return V_5 ;
}
int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const void T_1 * V_36 , int V_40 )
{
int V_5 ;
F_2 ( L_7 ,
V_40 , V_4 -> V_29 , V_4 -> V_30 ) ;
if ( V_2 -> V_43 )
return - V_44 ;
if ( V_4 -> V_30 + V_40 > V_4 -> V_29 )
V_40 = V_4 -> V_29 - V_4 -> V_30 ;
V_5 = F_23 ( V_4 -> V_23 + V_4 -> V_30 , V_36 , V_40 ) ;
if ( V_5 )
return - V_45 ;
V_4 -> V_30 += V_40 ;
if ( V_4 -> V_30 == V_4 -> V_29 ) {
int V_37 = F_17 ( ( int ) V_4 -> V_29 , V_2 -> V_35 ) ;
memset ( V_4 -> V_23 + V_4 -> V_29 , 0xFF ,
V_37 - V_4 -> V_29 ) ;
V_37 = F_19 ( V_2 , V_4 -> V_23 , V_37 ) ;
V_5 = F_16 ( V_2 , V_4 , V_4 -> V_34 ,
V_4 -> V_23 , V_37 ) ;
if ( V_5 )
return V_5 ;
}
F_3 ( V_4 -> V_30 <= V_4 -> V_29 ) ;
if ( V_4 -> V_30 == V_4 -> V_29 ) {
V_4 -> V_22 = 0 ;
V_5 = V_40 ;
F_13 ( V_4 -> V_23 ) ;
}
return V_5 ;
}
