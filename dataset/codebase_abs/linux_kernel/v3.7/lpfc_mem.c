int
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
int V_7 ;
if ( V_2 -> V_8 == V_9 )
V_2 -> V_10 =
F_2 ( L_1 ,
V_2 -> V_11 ,
V_2 -> V_12 ,
V_2 -> V_12 ,
0 ) ;
else
V_2 -> V_10 =
F_2 ( L_1 ,
V_2 -> V_11 , V_2 -> V_12 ,
V_3 , 0 ) ;
if ( ! V_2 -> V_10 )
goto V_13;
V_2 -> V_14 = F_2 ( L_2 , V_2 -> V_11 ,
V_15 ,
V_3 , 0 ) ;
if ( ! V_2 -> V_14 )
goto V_16;
V_5 -> V_17 = F_3 ( sizeof( struct V_18 ) *
V_19 , V_20 ) ;
if ( ! V_5 -> V_17 )
goto V_21;
V_5 -> V_22 = 0 ;
V_5 -> V_23 = 0 ;
for ( V_7 = 0 ; V_7 < V_19 ; V_7 ++ ) {
V_5 -> V_17 [ V_7 ] . V_24 = F_4 ( V_2 -> V_14 ,
V_20 , & V_5 -> V_17 [ V_7 ] . V_25 ) ;
if ( ! V_5 -> V_17 [ V_7 ] . V_24 )
goto V_26;
V_5 -> V_22 ++ ;
V_5 -> V_23 ++ ;
}
V_2 -> V_27 = F_5 ( V_28 ,
sizeof( V_29 ) ) ;
if ( ! V_2 -> V_27 )
goto V_26;
V_2 -> V_30 = F_5 ( V_28 ,
sizeof( struct V_31 ) ) ;
if ( ! V_2 -> V_30 )
goto V_32;
if ( V_2 -> V_8 == V_9 ) {
V_2 -> V_33 =
F_5 ( V_28 ,
sizeof( struct V_34 ) ) ;
if ( ! V_2 -> V_33 )
goto V_35;
V_2 -> V_36 = F_2 ( L_3 ,
V_2 -> V_11 ,
V_37 , V_3 , 0 ) ;
if ( ! V_2 -> V_36 )
goto V_38;
V_2 -> V_39 = F_2 ( L_4 ,
V_2 -> V_11 ,
V_40 , V_3 , 0 ) ;
if ( ! V_2 -> V_39 )
goto V_41;
V_2 -> V_42 = NULL ;
} else {
V_2 -> V_42 = F_2 ( L_5 ,
V_2 -> V_11 , V_15 , V_3 , 0 ) ;
if ( ! V_2 -> V_42 )
goto V_35;
V_2 -> V_36 = NULL ;
V_2 -> V_39 = NULL ;
}
return 0 ;
V_41:
F_6 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
V_38:
F_7 ( V_2 -> V_33 ) ;
V_2 -> V_33 = NULL ;
V_35:
F_7 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
V_32:
F_7 ( V_2 -> V_27 ) ;
V_2 -> V_27 = NULL ;
V_26:
while ( V_7 -- )
F_8 ( V_2 -> V_14 , V_5 -> V_17 [ V_7 ] . V_24 ,
V_5 -> V_17 [ V_7 ] . V_25 ) ;
F_9 ( V_5 -> V_17 ) ;
V_21:
F_6 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
V_16:
F_6 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
V_13:
return - V_43 ;
}
void
F_10 ( struct V_1 * V_2 )
{
int V_7 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
F_11 ( V_2 ) ;
if ( V_2 -> V_39 )
F_6 ( V_2 -> V_39 ) ;
V_2 -> V_39 = NULL ;
if ( V_2 -> V_36 )
F_6 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
if ( V_2 -> V_42 )
F_6 ( V_2 -> V_42 ) ;
V_2 -> V_42 = NULL ;
if ( V_2 -> V_33 )
F_7 ( V_2 -> V_33 ) ;
V_2 -> V_33 = NULL ;
F_7 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
F_7 ( V_2 -> V_27 ) ;
V_2 -> V_27 = NULL ;
for ( V_7 = 0 ; V_7 < V_5 -> V_23 ; V_7 ++ )
F_8 ( V_2 -> V_14 , V_5 -> V_17 [ V_7 ] . V_24 ,
V_5 -> V_17 [ V_7 ] . V_25 ) ;
F_9 ( V_5 -> V_17 ) ;
F_6 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
F_6 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
return;
}
void
F_12 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = & V_2 -> V_46 ;
V_29 * V_47 , * V_48 ;
struct V_18 * V_49 ;
F_13 (mbox, next_mbox, &psli->mboxq, list) {
V_49 = (struct V_18 * ) ( V_47 -> V_50 ) ;
if ( V_49 ) {
F_14 ( V_2 , V_49 -> V_24 , V_49 -> V_25 ) ;
F_9 ( V_49 ) ;
}
F_15 ( & V_47 -> V_51 ) ;
F_16 ( V_47 , V_2 -> V_27 ) ;
}
F_13 (mbox, next_mbox, &psli->mboxq_cmpl, list) {
V_49 = (struct V_18 * ) ( V_47 -> V_50 ) ;
if ( V_49 ) {
F_14 ( V_2 , V_49 -> V_24 , V_49 -> V_25 ) ;
F_9 ( V_49 ) ;
}
F_15 ( & V_47 -> V_51 ) ;
F_16 ( V_47 , V_2 -> V_27 ) ;
}
F_17 ( & V_2 -> V_52 ) ;
V_45 -> V_53 &= ~ V_54 ;
F_18 ( & V_2 -> V_52 ) ;
if ( V_45 -> V_55 ) {
V_47 = V_45 -> V_55 ;
V_49 = (struct V_18 * ) ( V_47 -> V_50 ) ;
if ( V_49 ) {
F_14 ( V_2 , V_49 -> V_24 , V_49 -> V_25 ) ;
F_9 ( V_49 ) ;
}
F_16 ( V_47 , V_2 -> V_27 ) ;
V_45 -> V_55 = NULL ;
}
F_10 ( V_2 ) ;
F_9 ( V_45 -> V_56 ) ;
V_45 -> V_56 = NULL ;
return;
}
void *
F_19 ( struct V_1 * V_2 , int V_57 , T_1 * V_58 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
unsigned long V_59 ;
void * V_60 ;
V_60 = F_4 ( V_2 -> V_14 , V_20 , V_58 ) ;
F_20 ( & V_2 -> V_52 , V_59 ) ;
if ( ! V_60 && ( V_57 & V_61 ) && V_5 -> V_23 ) {
V_5 -> V_23 -- ;
V_60 = V_5 -> V_17 [ V_5 -> V_23 ] . V_24 ;
* V_58 = V_5 -> V_17 [ V_5 -> V_23 ] . V_25 ;
}
F_21 ( & V_2 -> V_52 , V_59 ) ;
return V_60 ;
}
void
F_22 ( struct V_1 * V_2 , void * V_24 , T_1 V_62 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
if ( V_5 -> V_23 < V_5 -> V_22 ) {
V_5 -> V_17 [ V_5 -> V_23 ] . V_24 = V_24 ;
V_5 -> V_17 [ V_5 -> V_23 ] . V_25 = V_62 ;
V_5 -> V_23 ++ ;
} else {
F_8 ( V_2 -> V_14 , V_24 , V_62 ) ;
}
return;
}
void
F_14 ( struct V_1 * V_2 , void * V_24 , T_1 V_62 )
{
unsigned long V_59 ;
F_20 ( & V_2 -> V_52 , V_59 ) ;
F_22 ( V_2 , V_24 , V_62 ) ;
F_21 ( & V_2 -> V_52 , V_59 ) ;
return;
}
struct V_63 *
F_23 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
V_64 = F_24 ( sizeof( struct V_63 ) , V_20 ) ;
if ( ! V_64 )
return NULL ;
V_64 -> V_65 . V_24 = F_4 ( V_2 -> V_42 , V_20 ,
& V_64 -> V_65 . V_25 ) ;
if ( ! V_64 -> V_65 . V_24 ) {
F_9 ( V_64 ) ;
return NULL ;
}
V_64 -> V_66 = V_15 ;
return V_64 ;
}
void
F_25 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
F_8 ( V_2 -> V_42 , V_64 -> V_65 . V_24 , V_64 -> V_65 . V_25 ) ;
F_9 ( V_64 ) ;
return;
}
struct V_63 *
F_26 ( struct V_1 * V_2 )
{
struct V_63 * V_67 ;
V_67 = F_24 ( sizeof( struct V_63 ) , V_20 ) ;
if ( ! V_67 )
return NULL ;
V_67 -> V_68 . V_24 = F_4 ( V_2 -> V_36 , V_20 ,
& V_67 -> V_68 . V_25 ) ;
if ( ! V_67 -> V_68 . V_24 ) {
F_9 ( V_67 ) ;
return NULL ;
}
V_67 -> V_65 . V_24 = F_4 ( V_2 -> V_39 , V_20 ,
& V_67 -> V_65 . V_25 ) ;
if ( ! V_67 -> V_65 . V_24 ) {
F_8 ( V_2 -> V_36 , V_67 -> V_68 . V_24 ,
V_67 -> V_68 . V_25 ) ;
F_9 ( V_67 ) ;
return NULL ;
}
V_67 -> V_66 = V_15 ;
return V_67 ;
}
void
F_27 ( struct V_1 * V_2 , struct V_63 * V_69 )
{
F_8 ( V_2 -> V_36 , V_69 -> V_68 . V_24 , V_69 -> V_68 . V_25 ) ;
F_8 ( V_2 -> V_39 , V_69 -> V_65 . V_24 , V_69 -> V_65 . V_25 ) ;
F_9 ( V_69 ) ;
return;
}
void
F_28 ( struct V_1 * V_2 , struct V_18 * V_49 )
{
struct V_63 * V_70 ;
unsigned long V_71 ;
if ( ! V_49 )
return;
if ( V_2 -> V_72 & V_73 ) {
F_20 ( & V_2 -> V_52 , V_71 ) ;
if ( ! V_2 -> V_74 ) {
F_21 ( & V_2 -> V_52 , V_71 ) ;
return;
}
V_70 = F_29 ( V_49 , struct V_63 , V_65 ) ;
F_15 ( & V_70 -> V_65 . V_51 ) ;
if ( V_70 -> V_75 == - 1 ) {
( V_2 -> V_76 [ V_77 ] . V_78 )
( V_2 , V_70 ) ;
} else {
F_30 ( V_2 , V_70 ) ;
}
F_21 ( & V_2 -> V_52 , V_71 ) ;
} else {
F_14 ( V_2 , V_49 -> V_24 , V_49 -> V_25 ) ;
F_9 ( V_49 ) ;
}
return;
}
