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
int V_23 = 1 << F_6 ( V_15 , V_24 ) ;
V_20 = V_16 -> V_11 & ~ 0x3 ;
V_21 = F_7 ( V_17 - V_20 + 1 , 4 ) ;
if ( V_21 > V_23 ) {
V_21 = V_23 ;
V_17 = V_20 + V_21 - 1 ;
}
V_19 = F_8 ( V_15 , V_20 , V_21 ) ;
if ( ! V_19 ) {
F_9 ( V_15 , L_1 ) ;
return NULL ;
}
V_22 = F_10 ( V_15 , V_19 ) ;
if ( V_22 ) {
F_9 ( V_15 , L_2 , V_22 ) ;
goto V_25;
}
for ( V_9 = & V_16 -> V_9 ; V_9 ; V_9 = F_11 ( V_9 ) ) {
struct V_3 * V_4 = F_12 ( V_9 , struct V_3 , V_9 ) ;
struct V_26 * V_27 = & V_4 -> V_28 ;
T_2 V_29 ;
T_2 V_30 ;
if ( V_4 -> V_11 > V_17 )
break;
F_13 ( V_15 , V_19 ,
V_4 -> V_11 , & V_29 , & V_30 ) ;
if ( V_27 -> V_29 == V_29 )
continue;
V_27 -> V_29 = V_29 ;
V_27 -> V_30 = V_30 ;
V_27 -> V_31 = V_32 ;
}
V_25:
F_14 ( V_19 ) ;
return V_9 ;
}
static void F_15 ( struct V_33 * V_34 )
{
struct V_14 * V_15 = F_2 ( V_34 , struct V_14 ,
V_35 . V_36 . V_34 . V_34 ) ;
struct V_37 * V_36 = & V_15 -> V_35 . V_36 ;
unsigned long V_38 = V_32 ;
struct V_3 * V_4 = NULL ;
struct V_3 * V_39 = NULL ;
struct V_5 * V_9 ;
F_16 ( V_40 ) ;
F_17 ( & V_36 -> V_41 ) ;
F_18 ( & V_36 -> V_42 , & V_40 ) ;
if ( ! F_19 ( & V_40 ) || ! F_20 ( & V_36 -> V_43 ) )
F_21 ( V_36 -> V_44 , & V_36 -> V_34 , V_45 ) ;
F_22 ( & V_36 -> V_41 ) ;
F_23 (counter, &tmplist, list)
F_1 ( & V_36 -> V_43 , V_4 ) ;
V_9 = F_24 ( & V_36 -> V_43 ) ;
while ( V_9 ) {
V_4 = F_12 ( V_9 , struct V_3 , V_9 ) ;
V_9 = F_11 ( V_9 ) ;
if ( V_4 -> V_46 ) {
F_25 ( & V_4 -> V_9 , & V_36 -> V_43 ) ;
F_26 ( V_15 , V_4 -> V_11 ) ;
F_27 ( V_4 ) ;
continue;
}
V_39 = V_4 ;
}
if ( F_28 ( V_38 , V_36 -> V_47 ) || ! V_39 )
return;
V_9 = F_24 ( & V_36 -> V_43 ) ;
while ( V_9 ) {
V_4 = F_12 ( V_9 , struct V_3 , V_9 ) ;
V_9 = F_5 ( V_15 , V_4 , V_39 -> V_11 ) ;
}
V_36 -> V_47 = V_38 + V_45 ;
}
struct V_3 * F_29 ( struct V_14 * V_15 , bool V_48 )
{
struct V_37 * V_36 = & V_15 -> V_35 . V_36 ;
struct V_3 * V_4 ;
int V_22 ;
V_4 = F_30 ( sizeof( * V_4 ) , V_49 ) ;
if ( ! V_4 )
return F_31 ( - V_50 ) ;
V_22 = F_32 ( V_15 , & V_4 -> V_11 ) ;
if ( V_22 )
goto V_51;
if ( V_48 ) {
V_4 -> V_28 . V_31 = V_32 ;
V_4 -> V_48 = true ;
F_17 ( & V_36 -> V_41 ) ;
F_33 ( & V_4 -> V_52 , & V_36 -> V_42 ) ;
F_22 ( & V_36 -> V_41 ) ;
F_34 ( V_36 -> V_44 , & V_36 -> V_34 , 0 ) ;
}
return V_4 ;
V_51:
F_27 ( V_4 ) ;
return F_31 ( V_22 ) ;
}
void F_35 ( struct V_14 * V_15 , struct V_3 * V_4 )
{
struct V_37 * V_36 = & V_15 -> V_35 . V_36 ;
if ( ! V_4 )
return;
if ( V_4 -> V_48 ) {
V_4 -> V_46 = true ;
F_34 ( V_36 -> V_44 , & V_36 -> V_34 , 0 ) ;
return;
}
F_26 ( V_15 , V_4 -> V_11 ) ;
F_27 ( V_4 ) ;
}
int F_36 ( struct V_14 * V_15 )
{
struct V_37 * V_36 = & V_15 -> V_35 . V_36 ;
V_36 -> V_43 = V_53 ;
F_37 ( & V_36 -> V_42 ) ;
F_38 ( & V_36 -> V_41 ) ;
V_36 -> V_44 = F_39 ( L_3 ) ;
if ( ! V_36 -> V_44 )
return - V_50 ;
F_40 ( & V_36 -> V_34 , F_15 ) ;
return 0 ;
}
void F_41 ( struct V_14 * V_15 )
{
struct V_37 * V_36 = & V_15 -> V_35 . V_36 ;
struct V_3 * V_4 ;
struct V_3 * V_54 ;
struct V_5 * V_9 ;
F_42 ( & V_15 -> V_35 . V_36 . V_34 ) ;
F_43 ( V_15 -> V_35 . V_36 . V_44 ) ;
V_15 -> V_35 . V_36 . V_44 = NULL ;
F_44 (counter, tmp, &fc_stats->addlist, list) {
F_45 ( & V_4 -> V_52 ) ;
F_26 ( V_15 , V_4 -> V_11 ) ;
F_27 ( V_4 ) ;
}
V_9 = F_24 ( & V_36 -> V_43 ) ;
while ( V_9 ) {
V_4 = F_12 ( V_9 , struct V_3 , V_9 ) ;
V_9 = F_11 ( V_9 ) ;
F_25 ( & V_4 -> V_9 , & V_36 -> V_43 ) ;
F_26 ( V_15 , V_4 -> V_11 ) ;
F_27 ( V_4 ) ;
}
}
void F_46 ( struct V_3 * V_4 ,
T_2 * V_30 , T_2 * V_29 , T_2 * V_31 )
{
struct V_26 V_27 ;
V_27 = V_4 -> V_28 ;
* V_30 = V_27 . V_30 - V_4 -> V_55 ;
* V_29 = V_27 . V_29 - V_4 -> V_56 ;
* V_31 = V_27 . V_31 ;
V_4 -> V_55 = V_27 . V_30 ;
V_4 -> V_56 = V_27 . V_29 ;
}
