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
if ( ! V_2 -> V_24 )
return;
if ( type == V_13 )
V_7 -> V_16 -> V_25 = sizeof( V_26 ) + sizeof( V_27 ) ;
else
V_7 -> V_16 -> V_25 = sizeof( V_26 ) ;
F_6 ( V_21 , V_2 , L_2 ,
V_7 -> V_16 -> V_25 ) ;
}
}
void F_7 ( struct V_28 * V_29 )
{
const int V_30 = sizeof( struct V_31 ) ;
struct V_32 * V_32 ;
struct V_1 * V_2 ;
struct V_31 * V_33 ;
V_27 V_34 , V_35 ;
V_2 = V_1 ( V_29 -> V_36 -> V_37 ) ;
if ( V_2 -> V_8 == V_13 )
return;
V_34 = F_8 ( V_29 ) ;
F_9 (bio, scmd->request) {
struct V_38 * V_39 = F_10 ( V_32 ) ;
struct V_40 V_41 ;
struct V_42 V_43 ;
unsigned int V_44 ;
if ( V_39 -> V_45 & V_46 )
break;
V_35 = F_11 ( V_39 ) & 0xffffffff ;
F_12 (iv, bip, iter) {
V_33 = F_13 ( V_41 . V_47 ) + V_41 . V_48 ;
for ( V_44 = 0 ; V_44 < V_41 . V_49 ; V_44 += V_30 , V_33 ++ ) {
if ( F_14 ( V_33 -> V_50 ) == V_35 )
V_33 -> V_50 = F_15 ( V_34 ) ;
V_35 ++ ;
V_34 ++ ;
}
F_16 ( V_33 ) ;
}
V_39 -> V_45 |= V_46 ;
}
}
void F_17 ( struct V_28 * V_29 , unsigned int V_51 )
{
const int V_30 = sizeof( struct V_31 ) ;
struct V_1 * V_2 ;
struct V_32 * V_32 ;
struct V_31 * V_33 ;
unsigned int V_44 , V_52 ;
V_27 V_34 , V_35 ;
V_2 = V_1 ( V_29 -> V_36 -> V_37 ) ;
if ( V_2 -> V_8 == V_13 || V_51 == 0 )
return;
V_52 = V_51 / F_18 ( V_29 ) ;
V_34 = F_8 ( V_29 ) ;
F_9 (bio, scmd->request) {
struct V_38 * V_39 = F_10 ( V_32 ) ;
struct V_40 V_41 ;
struct V_42 V_43 ;
V_35 = F_11 ( V_39 ) & 0xffffffff ;
F_12 (iv, bip, iter) {
V_33 = F_13 ( V_41 . V_47 ) + V_41 . V_48 ;
for ( V_44 = 0 ; V_44 < V_41 . V_49 ; V_44 += V_30 , V_33 ++ ) {
if ( V_52 == 0 ) {
F_16 ( V_33 ) ;
return;
}
if ( F_14 ( V_33 -> V_50 ) == V_34 )
V_33 -> V_50 = F_15 ( V_35 ) ;
V_35 ++ ;
V_34 ++ ;
V_52 -- ;
}
F_16 ( V_33 ) ;
}
}
}
