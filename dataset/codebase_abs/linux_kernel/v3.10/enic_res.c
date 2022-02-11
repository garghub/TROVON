int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 ;
int V_5 ;
V_5 = F_2 ( V_1 -> V_6 , V_1 -> V_7 ) ;
if ( V_5 ) {
F_3 ( F_4 ( V_1 ) ,
L_1 , V_5 ) ;
return V_5 ;
}
#define F_5 ( T_1 ) \
do { \
err = vnic_dev_spec(enic->vdev, \
offsetof(struct vnic_enet_config, m), \
sizeof(c->m), &c->m); \
if (err) { \
dev_err(enic_get_dev(enic), \
"Error getting %s, %d\n", #m, err); \
return err; \
} \
} while (0)
F_5 ( V_8 ) ;
F_5 ( V_9 ) ;
F_5 ( V_10 ) ;
F_5 ( V_11 ) ;
F_5 ( V_12 ) ;
F_5 ( V_13 ) ;
F_5 ( V_14 ) ;
F_5 ( V_15 ) ;
V_3 -> V_9 =
F_6 ( V_16 , V_17 ,
F_7 ( V_16 , V_18 ,
V_3 -> V_9 ) ) ;
V_3 -> V_9 &= 0xffffffe0 ;
V_3 -> V_10 =
F_6 ( V_16 , V_19 ,
F_7 ( V_16 , V_20 ,
V_3 -> V_10 ) ) ;
V_3 -> V_10 &= 0xffffffe0 ;
if ( V_3 -> V_11 == 0 )
V_3 -> V_11 = 1500 ;
V_3 -> V_11 = F_6 ( V_21 , V_22 ,
F_7 ( V_21 , V_23 ,
V_3 -> V_11 ) ) ;
V_3 -> V_14 = F_6 ( V_16 , V_3 -> V_14 ,
F_8 ( V_1 -> V_6 ) ) ;
F_9 ( F_4 ( V_1 ) ,
L_2 ,
V_1 -> V_7 , V_3 -> V_9 , V_3 -> V_10 , V_3 -> V_11 ) ;
F_9 ( F_4 ( V_1 ) , L_3
L_4
L_5 ,
F_10 ( V_1 , V_24 ) ? L_6 : L_7 ,
F_10 ( V_1 , V_25 ) ? L_6 : L_7 ,
F_10 ( V_1 , V_26 ) ? L_6 : L_7 ,
F_10 ( V_1 , V_27 ) ? L_6 : L_7 ,
F_10 ( V_1 , V_28 ) ? L_6 : L_7 ,
V_3 -> V_13 == V_29 ? L_8 :
V_3 -> V_13 == V_30 ? L_9 :
V_3 -> V_13 == V_31 ? L_10 :
L_11 ,
V_3 -> V_12 == V_32 ? L_12 :
V_3 -> V_12 == V_33 ? L_13 :
L_11 ,
V_3 -> V_14 ,
V_3 -> V_15 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_1 , V_21 V_34 )
{
T_2 V_35 = V_34 , V_36 = 0 ;
int V_37 = 1000 ;
int V_5 ;
V_5 = F_12 ( V_1 -> V_6 , V_38 , & V_35 , & V_36 , V_37 ) ;
if ( V_5 )
F_3 ( F_4 ( V_1 ) , L_14 , V_5 ) ;
return V_5 ;
}
int F_13 ( struct V_1 * V_1 , V_21 V_34 )
{
T_2 V_35 = V_34 , V_36 = 0 ;
int V_37 = 1000 ;
int V_5 ;
V_5 = F_12 ( V_1 -> V_6 , V_39 , & V_35 , & V_36 , V_37 ) ;
if ( V_5 )
F_3 ( F_4 ( V_1 ) , L_15 , V_5 ) ;
return V_5 ;
}
int F_14 ( struct V_1 * V_1 , T_3 V_40 , T_3 V_41 ,
T_3 V_42 , T_3 V_43 , T_3 V_44 , T_3 V_45 ,
T_3 V_46 )
{
T_2 V_35 , V_36 ;
V_16 V_47 ;
int V_37 = 1000 ;
F_15 ( & V_47 , V_40 ,
V_41 , V_42 , V_43 ,
V_44 , V_45 , V_46 ) ;
V_35 = V_47 ;
V_36 = 0 ;
return F_12 ( V_1 -> V_6 , V_48 , & V_35 , & V_36 , V_37 ) ;
}
int F_16 ( struct V_1 * V_1 , T_4 V_49 , T_2 V_50 )
{
T_2 V_35 = ( T_2 ) V_49 , V_36 = V_50 ;
int V_37 = 1000 ;
return F_12 ( V_1 -> V_6 , V_51 , & V_35 , & V_36 , V_37 ) ;
}
int F_17 ( struct V_1 * V_1 , T_4 V_52 , T_2 V_50 )
{
T_2 V_35 = ( T_2 ) V_52 , V_36 = V_50 ;
int V_37 = 1000 ;
return F_12 ( V_1 -> V_6 , V_53 , & V_35 , & V_36 , V_37 ) ;
}
void F_18 ( struct V_1 * V_1 )
{
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < V_1 -> V_55 ; V_54 ++ )
F_19 ( & V_1 -> V_56 [ V_54 ] ) ;
for ( V_54 = 0 ; V_54 < V_1 -> V_57 ; V_54 ++ )
F_20 ( & V_1 -> V_58 [ V_54 ] ) ;
for ( V_54 = 0 ; V_54 < V_1 -> V_59 ; V_54 ++ )
F_21 ( & V_1 -> V_60 [ V_54 ] ) ;
for ( V_54 = 0 ; V_54 < V_1 -> V_61 ; V_54 ++ )
F_22 ( & V_1 -> V_62 [ V_54 ] ) ;
}
void F_23 ( struct V_1 * V_1 )
{
V_1 -> V_55 = F_24 ( V_1 -> V_6 , V_63 ) ;
V_1 -> V_57 = F_24 ( V_1 -> V_6 , V_64 ) ;
V_1 -> V_59 = F_24 ( V_1 -> V_6 , V_65 ) ;
V_1 -> V_61 = F_24 ( V_1 -> V_6 ,
V_66 ) ;
F_9 ( F_4 ( V_1 ) ,
L_16 ,
V_1 -> V_55 , V_1 -> V_57 ,
V_1 -> V_59 , V_1 -> V_61 ) ;
}
void F_25 ( struct V_1 * V_1 )
{
enum V_67 V_13 ;
unsigned int V_68 ;
unsigned int V_69 ;
unsigned int V_70 ;
unsigned int V_71 ;
unsigned int V_72 ;
unsigned int V_54 ;
V_13 = F_26 ( V_1 -> V_6 ) ;
switch ( V_13 ) {
case V_73 :
case V_74 :
V_70 = 1 ;
V_71 = V_1 -> V_61 - 2 ;
break;
default:
V_70 = 0 ;
V_71 = 0 ;
break;
}
for ( V_54 = 0 ; V_54 < V_1 -> V_57 ; V_54 ++ ) {
V_72 = V_54 ;
F_27 ( & V_1 -> V_58 [ V_54 ] ,
V_72 ,
V_70 ,
V_71 ) ;
}
for ( V_54 = 0 ; V_54 < V_1 -> V_55 ; V_54 ++ ) {
V_72 = V_1 -> V_57 + V_54 ;
F_28 ( & V_1 -> V_56 [ V_54 ] ,
V_72 ,
V_70 ,
V_71 ) ;
}
for ( V_54 = 0 ; V_54 < V_1 -> V_59 ; V_54 ++ ) {
switch ( V_13 ) {
case V_74 :
V_69 = V_54 ;
break;
default:
V_69 = 0 ;
break;
}
F_29 ( & V_1 -> V_60 [ V_54 ] ,
0 ,
1 ,
0 ,
0 ,
1 ,
1 ,
1 ,
0 ,
V_69 ,
0 ) ;
}
switch ( V_13 ) {
case V_75 :
case V_74 :
V_68 = 1 ;
break;
default:
V_68 = 0 ;
break;
}
for ( V_54 = 0 ; V_54 < V_1 -> V_61 ; V_54 ++ ) {
F_30 ( & V_1 -> V_62 [ V_54 ] ,
V_1 -> V_4 . V_14 ,
V_1 -> V_4 . V_12 ,
V_68 ) ;
}
}
int F_31 ( struct V_1 * V_1 )
{
enum V_67 V_13 ;
unsigned int V_54 ;
int V_5 ;
V_13 = F_26 ( V_1 -> V_6 ) ;
F_9 ( F_4 ( V_1 ) , L_17
L_18 ,
V_1 -> V_55 , V_1 -> V_57 ,
V_1 -> V_59 , V_1 -> V_61 ,
V_13 == V_73 ? L_19 :
V_13 == V_75 ? L_9 :
V_13 == V_74 ? L_20 :
L_11 ) ;
for ( V_54 = 0 ; V_54 < V_1 -> V_55 ; V_54 ++ ) {
V_5 = F_32 ( V_1 -> V_6 , & V_1 -> V_56 [ V_54 ] , V_54 ,
V_1 -> V_4 . V_9 ,
sizeof( struct V_76 ) ) ;
if ( V_5 )
goto V_77;
}
for ( V_54 = 0 ; V_54 < V_1 -> V_57 ; V_54 ++ ) {
V_5 = F_33 ( V_1 -> V_6 , & V_1 -> V_58 [ V_54 ] , V_54 ,
V_1 -> V_4 . V_10 ,
sizeof( struct V_78 ) ) ;
if ( V_5 )
goto V_77;
}
for ( V_54 = 0 ; V_54 < V_1 -> V_59 ; V_54 ++ ) {
if ( V_54 < V_1 -> V_57 )
V_5 = F_34 ( V_1 -> V_6 , & V_1 -> V_60 [ V_54 ] , V_54 ,
V_1 -> V_4 . V_10 ,
sizeof( struct V_79 ) ) ;
else
V_5 = F_34 ( V_1 -> V_6 , & V_1 -> V_60 [ V_54 ] , V_54 ,
V_1 -> V_4 . V_9 ,
sizeof( struct V_80 ) ) ;
if ( V_5 )
goto V_77;
}
for ( V_54 = 0 ; V_54 < V_1 -> V_61 ; V_54 ++ ) {
V_5 = F_35 ( V_1 -> V_6 , & V_1 -> V_62 [ V_54 ] , V_54 ) ;
if ( V_5 )
goto V_77;
}
V_1 -> V_81 = F_36 ( V_1 -> V_6 ,
V_82 , 0 ) ;
if ( ! V_1 -> V_81 && V_13 == V_73 ) {
F_3 ( F_4 ( V_1 ) ,
L_21 ) ;
V_5 = - V_83 ;
goto V_77;
}
return 0 ;
V_77:
F_18 ( V_1 ) ;
return V_5 ;
}
