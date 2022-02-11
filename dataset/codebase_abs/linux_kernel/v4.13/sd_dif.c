void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 type = V_2 -> V_8 ;
struct V_9 V_10 ;
int V_11 , V_12 ;
V_11 = F_2 ( V_4 -> V_13 , type ) ;
V_12 = F_3 ( V_4 -> V_13 , type ) ;
if ( ! V_12 && F_3 ( V_4 -> V_13 , 0 ) ) {
V_11 = 0 ; V_12 = 1 ;
}
if ( ! V_12 )
return;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
if ( F_4 ( V_2 -> V_5 -> V_13 ) & V_14 ) {
if ( type == V_15 )
V_10 . V_16 = & V_17 ;
else
V_10 . V_16 = & V_18 ;
V_10 . V_19 |= V_20 ;
} else
if ( type == V_15 )
V_10 . V_16 = & V_21 ;
else
V_10 . V_16 = & V_22 ;
V_10 . V_23 = sizeof( struct V_24 ) ;
F_5 ( V_25 , V_2 ,
L_1 , V_10 . V_16 -> V_26 ) ;
if ( V_11 && type ) {
V_10 . V_19 |= V_27 ;
if ( ! V_2 -> V_28 )
goto V_29;
if ( type == V_15 )
V_10 . V_30 = sizeof( V_31 ) + sizeof( V_32 ) ;
else
V_10 . V_30 = sizeof( V_31 ) ;
F_5 ( V_25 , V_2 , L_2 ,
V_10 . V_30 ) ;
}
V_29:
F_6 ( V_7 , & V_10 ) ;
}
void F_7 ( struct V_33 * V_34 )
{
const int V_35 = sizeof( struct V_24 ) ;
struct V_36 * V_36 ;
struct V_1 * V_2 ;
struct V_24 * V_37 ;
V_32 V_38 , V_39 ;
V_2 = V_1 ( V_34 -> V_40 -> V_41 ) ;
if ( V_2 -> V_8 == V_15 )
return;
V_38 = F_8 ( V_34 ) ;
F_9 (bio, scmd->request) {
struct V_42 * V_43 = F_10 ( V_36 ) ;
struct V_44 V_45 ;
struct V_46 V_47 ;
unsigned int V_48 ;
if ( V_43 -> V_49 & V_50 )
break;
V_39 = F_11 ( V_43 ) & 0xffffffff ;
F_12 (iv, bip, iter) {
V_37 = F_13 ( V_45 . V_51 ) + V_45 . V_52 ;
for ( V_48 = 0 ; V_48 < V_45 . V_53 ; V_48 += V_35 , V_37 ++ ) {
if ( F_14 ( V_37 -> V_54 ) == V_39 )
V_37 -> V_54 = F_15 ( V_38 ) ;
V_39 ++ ;
V_38 ++ ;
}
F_16 ( V_37 ) ;
}
V_43 -> V_49 |= V_50 ;
}
}
void F_17 ( struct V_33 * V_34 , unsigned int V_55 )
{
const int V_35 = sizeof( struct V_24 ) ;
struct V_1 * V_2 ;
struct V_36 * V_36 ;
struct V_24 * V_37 ;
unsigned int V_48 , V_56 ;
V_32 V_38 , V_39 ;
V_2 = V_1 ( V_34 -> V_40 -> V_41 ) ;
if ( V_2 -> V_8 == V_15 || V_55 == 0 )
return;
V_56 = V_55 / F_18 ( V_34 ) ;
V_38 = F_8 ( V_34 ) ;
F_9 (bio, scmd->request) {
struct V_42 * V_43 = F_10 ( V_36 ) ;
struct V_44 V_45 ;
struct V_46 V_47 ;
V_39 = F_11 ( V_43 ) & 0xffffffff ;
F_12 (iv, bip, iter) {
V_37 = F_13 ( V_45 . V_51 ) + V_45 . V_52 ;
for ( V_48 = 0 ; V_48 < V_45 . V_53 ; V_48 += V_35 , V_37 ++ ) {
if ( V_56 == 0 ) {
F_16 ( V_37 ) ;
return;
}
if ( F_14 ( V_37 -> V_54 ) == V_38 )
V_37 -> V_54 = F_15 ( V_39 ) ;
V_39 ++ ;
V_38 ++ ;
V_56 -- ;
}
F_16 ( V_37 ) ;
}
}
}
