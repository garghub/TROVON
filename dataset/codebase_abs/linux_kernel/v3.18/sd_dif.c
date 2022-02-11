void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 type = V_2 -> V_8 ;
int V_9 , V_10 ;
V_9 = F_2 ( V_4 -> V_11 , type ) ;
V_10 = F_3 ( V_4 -> V_11 , type ) ;
if ( ! V_10 && F_3 ( V_4 -> V_11 , 0 ) ) {
V_9 = 0 ; V_10 = 1 ;
}
if ( ! V_10 )
return;
if ( F_4 ( V_2 -> V_5 -> V_11 ) & V_12 ) {
if ( type == V_13 )
F_5 ( V_7 , & V_14 ) ;
else
F_5 ( V_7 , & V_15 ) ;
V_7 -> V_16 -> V_17 |= V_18 ;
} else
if ( type == V_13 )
F_5 ( V_7 , & V_19 ) ;
else
F_5 ( V_7 , & V_20 ) ;
F_6 ( V_21 , V_2 ,
L_1 , V_7 -> V_16 -> V_22 ) ;
if ( V_9 && type ) {
V_7 -> V_16 -> V_17 |= V_23 ;
if ( ! V_2 )
return;
if ( type == V_13 )
V_7 -> V_16 -> V_24 = sizeof( V_25 ) + sizeof( V_26 ) ;
else
V_7 -> V_16 -> V_24 = sizeof( V_25 ) ;
F_6 ( V_21 , V_2 , L_2 ,
V_7 -> V_16 -> V_24 ) ;
}
}
void F_7 ( struct V_27 * V_28 )
{
const int V_29 = sizeof( struct V_30 ) ;
struct V_31 * V_31 ;
struct V_1 * V_2 ;
struct V_30 * V_32 ;
V_26 V_33 , V_34 ;
V_2 = V_1 ( V_28 -> V_35 -> V_36 ) ;
if ( V_2 -> V_8 == V_13 )
return;
V_33 = F_8 ( V_28 ) ;
F_9 (bio, scmd->request) {
struct V_37 * V_38 = F_10 ( V_31 ) ;
struct V_39 V_40 ;
struct V_41 V_42 ;
unsigned int V_43 ;
if ( V_38 -> V_44 & V_45 )
break;
V_34 = F_11 ( V_38 ) & 0xffffffff ;
F_12 (iv, bip, iter) {
V_32 = F_13 ( V_40 . V_46 ) + V_40 . V_47 ;
for ( V_43 = 0 ; V_43 < V_40 . V_48 ; V_43 += V_29 , V_32 ++ ) {
if ( F_14 ( V_32 -> V_49 ) == V_34 )
V_32 -> V_49 = F_15 ( V_33 ) ;
V_34 ++ ;
V_33 ++ ;
}
F_16 ( V_32 ) ;
}
V_38 -> V_44 |= V_45 ;
}
}
void F_17 ( struct V_27 * V_28 , unsigned int V_50 )
{
const int V_29 = sizeof( struct V_30 ) ;
struct V_1 * V_2 ;
struct V_31 * V_31 ;
struct V_30 * V_32 ;
unsigned int V_43 , V_51 ;
V_26 V_33 , V_34 ;
V_2 = V_1 ( V_28 -> V_35 -> V_36 ) ;
if ( V_2 -> V_8 == V_13 || V_50 == 0 )
return;
V_51 = V_50 / F_18 ( V_28 ) ;
V_33 = F_8 ( V_28 ) ;
F_9 (bio, scmd->request) {
struct V_37 * V_38 = F_10 ( V_31 ) ;
struct V_39 V_40 ;
struct V_41 V_42 ;
V_34 = F_11 ( V_38 ) & 0xffffffff ;
F_12 (iv, bip, iter) {
V_32 = F_13 ( V_40 . V_46 ) + V_40 . V_47 ;
for ( V_43 = 0 ; V_43 < V_40 . V_48 ; V_43 += V_29 , V_32 ++ ) {
if ( V_51 == 0 ) {
F_16 ( V_32 ) ;
return;
}
if ( F_14 ( V_32 -> V_49 ) == V_33 )
V_32 -> V_49 = F_15 ( V_34 ) ;
V_34 ++ ;
V_33 ++ ;
V_51 -- ;
}
F_16 ( V_32 ) ;
}
}
}
