static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * * V_6 = & V_2 -> V_5 ;
struct V_5 * V_7 = NULL ;
while ( * V_6 ) {
struct V_3 * V_8 = F_2 ( * V_6 , struct V_3 , V_9 ) ;
int V_10 = V_4 -> V_11 - V_8 -> V_11 ;
V_7 = * V_6 ;
if ( V_10 < 0 )
V_6 = & ( ( * V_6 ) -> V_12 ) ;
else
V_6 = & ( ( * V_6 ) -> V_13 ) ;
}
F_3 ( & V_4 -> V_9 , V_7 , V_6 ) ;
F_4 ( & V_4 -> V_9 , V_2 ) ;
}
static struct V_5 * F_5 ( struct V_14 * V_15 ,
struct V_3 * V_16 ,
T_1 V_17 )
{
struct V_18 * V_19 ;
struct V_5 * V_9 = NULL ;
T_1 V_20 ;
int V_21 ;
int V_22 ;
int V_23 = F_6 ( int , V_24 ,
( 1 << F_7 ( V_15 , V_25 ) ) ) ;
V_20 = V_16 -> V_11 & ~ 0x3 ;
V_21 = F_8 ( V_17 - V_20 + 1 , 4 ) ;
if ( V_21 > V_23 ) {
V_21 = V_23 ;
V_17 = V_20 + V_21 - 1 ;
}
V_19 = F_9 ( V_15 , V_20 , V_21 ) ;
if ( ! V_19 ) {
F_10 ( V_15 , L_1 ) ;
return NULL ;
}
V_22 = F_11 ( V_15 , V_19 ) ;
if ( V_22 ) {
F_10 ( V_15 , L_2 , V_22 ) ;
goto V_26;
}
for ( V_9 = & V_16 -> V_9 ; V_9 ; V_9 = F_12 ( V_9 ) ) {
struct V_3 * V_4 = F_2 ( V_9 , struct V_3 , V_9 ) ;
struct V_27 * V_28 = & V_4 -> V_29 ;
T_2 V_30 ;
T_2 V_31 ;
if ( V_4 -> V_11 > V_17 )
break;
F_13 ( V_15 , V_19 ,
V_4 -> V_11 , & V_30 , & V_31 ) ;
if ( V_28 -> V_30 == V_30 )
continue;
V_28 -> V_30 = V_30 ;
V_28 -> V_31 = V_31 ;
V_28 -> V_32 = V_33 ;
}
V_26:
F_14 ( V_19 ) ;
return V_9 ;
}
static void F_15 ( struct V_34 * V_35 )
{
struct V_14 * V_15 = F_16 ( V_35 , struct V_14 ,
V_36 . V_37 . V_35 . V_35 ) ;
struct V_38 * V_37 = & V_15 -> V_36 . V_37 ;
unsigned long V_39 = V_33 ;
struct V_3 * V_4 = NULL ;
struct V_3 * V_40 = NULL ;
struct V_5 * V_9 ;
F_17 ( V_41 ) ;
F_18 ( & V_37 -> V_42 ) ;
F_19 ( & V_37 -> V_43 , & V_41 ) ;
if ( ! F_20 ( & V_41 ) || ! F_21 ( & V_37 -> V_44 ) )
F_22 ( V_37 -> V_45 , & V_37 -> V_35 ,
V_37 -> V_46 ) ;
F_23 ( & V_37 -> V_42 ) ;
F_24 (counter, &tmplist, list)
F_1 ( & V_37 -> V_44 , V_4 ) ;
V_9 = F_25 ( & V_37 -> V_44 ) ;
while ( V_9 ) {
V_4 = F_2 ( V_9 , struct V_3 , V_9 ) ;
V_9 = F_12 ( V_9 ) ;
if ( V_4 -> V_47 ) {
F_26 ( & V_4 -> V_9 , & V_37 -> V_44 ) ;
F_27 ( V_15 , V_4 -> V_11 ) ;
F_28 ( V_4 ) ;
continue;
}
V_40 = V_4 ;
}
if ( F_29 ( V_39 , V_37 -> V_48 ) || ! V_40 )
return;
V_9 = F_25 ( & V_37 -> V_44 ) ;
while ( V_9 ) {
V_4 = F_2 ( V_9 , struct V_3 , V_9 ) ;
V_9 = F_5 ( V_15 , V_4 , V_40 -> V_11 ) ;
}
V_37 -> V_48 = V_39 + V_37 -> V_46 ;
}
struct V_3 * F_30 ( struct V_14 * V_15 , bool V_49 )
{
struct V_38 * V_37 = & V_15 -> V_36 . V_37 ;
struct V_3 * V_4 ;
int V_22 ;
V_4 = F_31 ( sizeof( * V_4 ) , V_50 ) ;
if ( ! V_4 )
return F_32 ( - V_51 ) ;
V_22 = F_33 ( V_15 , & V_4 -> V_11 ) ;
if ( V_22 )
goto V_52;
if ( V_49 ) {
V_4 -> V_29 . V_32 = V_33 ;
V_4 -> V_49 = true ;
F_18 ( & V_37 -> V_42 ) ;
F_34 ( & V_4 -> V_53 , & V_37 -> V_43 ) ;
F_23 ( & V_37 -> V_42 ) ;
F_35 ( V_37 -> V_45 , & V_37 -> V_35 , 0 ) ;
}
return V_4 ;
V_52:
F_28 ( V_4 ) ;
return F_32 ( V_22 ) ;
}
void F_36 ( struct V_14 * V_15 , struct V_3 * V_4 )
{
struct V_38 * V_37 = & V_15 -> V_36 . V_37 ;
if ( ! V_4 )
return;
if ( V_4 -> V_49 ) {
V_4 -> V_47 = true ;
F_35 ( V_37 -> V_45 , & V_37 -> V_35 , 0 ) ;
return;
}
F_27 ( V_15 , V_4 -> V_11 ) ;
F_28 ( V_4 ) ;
}
int F_37 ( struct V_14 * V_15 )
{
struct V_38 * V_37 = & V_15 -> V_36 . V_37 ;
V_37 -> V_44 = V_54 ;
F_38 ( & V_37 -> V_43 ) ;
F_39 ( & V_37 -> V_42 ) ;
V_37 -> V_45 = F_40 ( L_3 ) ;
if ( ! V_37 -> V_45 )
return - V_51 ;
V_37 -> V_46 = V_55 ;
F_41 ( & V_37 -> V_35 , F_15 ) ;
return 0 ;
}
void F_42 ( struct V_14 * V_15 )
{
struct V_38 * V_37 = & V_15 -> V_36 . V_37 ;
struct V_3 * V_4 ;
struct V_3 * V_56 ;
struct V_5 * V_9 ;
F_43 ( & V_15 -> V_36 . V_37 . V_35 ) ;
F_44 ( V_15 -> V_36 . V_37 . V_45 ) ;
V_15 -> V_36 . V_37 . V_45 = NULL ;
F_45 (counter, tmp, &fc_stats->addlist, list) {
F_46 ( & V_4 -> V_53 ) ;
F_27 ( V_15 , V_4 -> V_11 ) ;
F_28 ( V_4 ) ;
}
V_9 = F_25 ( & V_37 -> V_44 ) ;
while ( V_9 ) {
V_4 = F_2 ( V_9 , struct V_3 , V_9 ) ;
V_9 = F_12 ( V_9 ) ;
F_26 ( & V_4 -> V_9 , & V_37 -> V_44 ) ;
F_27 ( V_15 , V_4 -> V_11 ) ;
F_28 ( V_4 ) ;
}
}
void F_47 ( struct V_3 * V_4 ,
T_2 * V_31 , T_2 * V_30 , T_2 * V_32 )
{
struct V_27 V_28 ;
V_28 = V_4 -> V_29 ;
* V_31 = V_28 . V_31 - V_4 -> V_57 ;
* V_30 = V_28 . V_30 - V_4 -> V_58 ;
* V_32 = V_28 . V_32 ;
V_4 -> V_57 = V_28 . V_31 ;
V_4 -> V_58 = V_28 . V_30 ;
}
void F_48 ( struct V_14 * V_15 ,
struct V_59 * V_60 ,
unsigned long V_61 )
{
struct V_38 * V_37 = & V_15 -> V_36 . V_37 ;
F_22 ( V_37 -> V_45 , V_60 , V_61 ) ;
}
void F_49 ( struct V_14 * V_15 ,
unsigned long V_62 )
{
struct V_38 * V_37 = & V_15 -> V_36 . V_37 ;
V_37 -> V_46 = F_6 (unsigned long, interval,
fc_stats->sampling_interval) ;
}
